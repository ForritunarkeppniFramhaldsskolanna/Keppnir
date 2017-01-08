jQuery.extend(jQuery.ns('Kattis.views.contest.resolver'), {
    init: function () {
        var data = this.data,
            info = data['info'],
            length = info['length'],
            cutoff = info['cutoff'];

        jQuery(function ($) {
            var control_window = window.open("", "Kattis Resolver", "width=450, height=400");
            control_window.document.open();
            control_window.document.write($('#resolver_controls_wrapper').html());
            control_window.document.title = 'Controls';

            function get_cw_elem(id) {
                return $(control_window.document.getElementById(id));
            }
            function update_cell_width() {
                $('.team_problem_cell').css('width', get_cw_elem('resolver_cell_width').val() + 'px');
            }

            get_cw_elem('resolver_cell_width').change(update_cell_width);

            var table_header_tmpl = tmpl('table_header_tmpl');
            var team_row_tmpl = tmpl('team_row_tmpl');

            function focus_on_element(elem, callback) {
                $('html, body').stop().animate({ scrollTop: elem.offset().top - $(window).height() / 2 + elem.height() / 2 }, 200, function () {
                    if (callback) {
                        callback();
                    }
                });
            }

            function Team(team, problems) {

                var row = $(team_row_tmpl({ team: team, problems: problems }));
                var no_cell = row.children('.rank');
                var points_cell = row.children('.score');
                var time_cell = row.children('.time');
                var problem_cells = row.children('.team_problem_cell');

                var ps = {};
                for (var i = 0; i < problems.length; i++) {
                    var problem_id = problems[i]['id'];

                    ps[problem_id] = {
                        cell: $(problem_cells[i]),
                        score: 0,
                        submissions: 0,
                        pending: [],
                        last_improvement: 0,
                        max_score: problems[i]['max_score']
                    };
                }

                return {
                    id: team['id'],
                    name: team['name'],
                    row: row,
                    cur_row: row,
                    no_cell: no_cell,
                    points_cell: points_cell,
                    time_cell: time_cell,
                    problems: ps,
                    points: 0,

                    get_last_improvement: function () {
                        var res = 0;
                        for (var i = 0; i < problem_ids.length; i++) {
                            res = Math.max(res, this.problems[problem_ids[i]].last_improvement);
                        }
                        return res;
                    },

                    reset: function () {
                        this.no_cell.text('');
                        this.points_cell.text('0');
                        this.time_cell.text('0');
                        this.points = 0;
                        for (var i = 0; i < problem_ids.length; i++) {
                            var id = problem_ids[i];
                            this.problems[id].score = 0;
                            this.problems[id].submissions = 0;
                            this.problems[id].last_improvement = 0;
                            this.problems[id].pending = [];
                            this.problems[id].cell.empty();
                            this.problems[id].cell.removeClass('solved attempted partial-score pending');
                        }
                    },

                    handle_submission: function (sub, resolving, check_only) {
                        // Note: sub will come in increasing order of time, except when resolving=true
                        if (!sub['judged']) return false;
                        var problem_id = sub['problem'];
                        var verdict = sub['result'];
                        var problem = this.problems[problem_id];
                        if (verdict === 'CE') return false;
                        if (Math.abs(problem.score - problem.max_score) < 1e-9) return false;

                        var prev_score = problem.score;
                        var after_freeze = sub['time'] >= (length - cutoff) / 60.0;
                        if (!after_freeze || resolving) {
                            problem.submissions++;
                            this.points -= problem.score;
                            if (sub['score'] > problem.score + 1e-9) {
                                problem.score = sub['score'];
                                problem.last_improvement = Math.floor(sub['time']);
                            } else if (Math.abs(sub['score'] - problem.score) < 1e-9) {
                                problem.last_improvement = Math.min(problem.last_improvement, Math.floor(sub['time']));
                            }
                            this.points += problem.score;
                        }
                        if (after_freeze) {
                            if (resolving) {
                                var i = 0;
                                while (i < problem.pending.length && problem.pending[i] !== sub) i++;
                                console.log(i, problem.pending.length);
                                if (i < problem.pending.length) {
                                    problem.pending[i] = problem.pending[problem.pending.length - 1];
                                    problem.pending.pop();
                                }
                                problem.pending.sort(function (a,b) { return b['time'] - a['time']; });
                            } else {
                                problem.pending.push(sub);
                            }
                        }

                        if (!check_only) {
                            this.points_cell.text(this.points);
                            this.time_cell.text(this.get_last_improvement());
                            problem.cell.html(problem.score + '<br/>' + problem.submissions + (problem.pending.length > 0 ? '+' + problem.pending.length : ''));

                            problem.cell.removeClass('solved attempted partial-score pending');
                            if (Math.abs(problem.score - problem.max_score) < 1e-9) {
                                problem.cell.addClass('solved');
                            } else if (problem.pending.length > 0) {
                                problem.cell.addClass('pending');
                            } else if (problem.score === 0) {
                                problem.cell.addClass('attempted');
                            } else {
                                problem.cell.addClass('partial-score');
                            }
                        }

                        return true;
                    }
                };
            }

            function get_time_multiplier() {
                return parseFloat(get_cw_elem('resolver_time_multiplier').val());
            }
            function get_row_animate_time() {
                return parseInt(get_cw_elem('resolver_row_animate_time').val(), 10);
            }

            function row_animate(team, time, standings, row, no, callback) {
                var at = row.offset();
                var height = row.height();
                var width = row.width();

                var fills = [];
                for (var i = 0; i < 2; i++) {
                    fills.push(
                        $('<tr></tr>').append(
                            $('<td></td>', { 'colspan': 4 + problems.length })
                                .css({
                                    'height': '0',
                                    'margin': '0',
                                    'padding': '0'
                                })
                        )
                    );
                }

                fills[0].height(0).width(width);
                row.replaceWith(fills[1]);
                team.cur_row = fills[1];
                fills[1].height(height).width(width);
                row.height(height).width(width);

                var div = $('<div></div>');
                div.append($('<table></table>')
                                .addClass('table table-kattis kattis-table-contest-standings')
                                .css({ 'border-top': 'none',
                                    'border-radius': 'none' })
                                .append($('<tbody></tbody>').append(row)))
                .width(width)
                .height(height)
                .css({
                        'position': 'absolute',
                        'top': at.top + 'px',
                        'left': (at.left+1) + 'px'
                })
                .appendTo($('#wrapper'));

                if (no === 0) {
                    fills[0].prependTo($('#standings tbody'));
                } else {
                    fills[0].insertAfter(standings[no - 1].row);
                }

                team.cur_row = fills[0];
                fills[1].animate({ 'height': '0' }, time);
                fills[0].animate({ 'height': height }, time);

                div.animate({ 'top': fills[0].offset().top + 'px' }, time, function () {
                    row.width('auto').height('auto');
                    fills[0].replaceWith(row);
                    team.cur_row = row;
                    div.remove();
                    fills[1].remove();
                    if (callback) {
                        callback();
                    }
                });
            }

            function update_standings(standings, animate, callback) {
                standings.sort(function (a, b) {
                    if (a.points !== b.points) return b.points - a.points;
                    var ali = a.get_last_improvement(),
                        bli = b.get_last_improvement();
                    if (Math.abs(ali - bli) > 1e-9) {
                        return ali - bli;
                    }
                    if (a.name !== b.name) return a.name.localeCompare(b.name);
                    return 0;
                });

                var row_at = 0;
                (function next_row() {
                    if (row_at === standings.length) {
                        if (callback) {
                            callback();
                        }
                    } else {
                        var old_no = standings[row_at].row.index() + 1,
                            no = row_at + 1;
                        if (standings[row_at].points > 0) {
                            standings[row_at].no_cell.text(no);
                        } else {
                            standings[row_at].no_cell.text('');
                        }
                        if (no < old_no) {
                            if (animate) {
                                var time = get_row_animate_time() * (Math.abs(no - old_no) + 1);
                                row_animate(standings[row_at], time, standings, standings[row_at].row, no - 1, function () {
                                    row_at += 1;
                                    next_row();
                                });
                            } else {
                                standings[row_at].row.detach();
                                if (no === 1) {
                                    standings[row_at].row.prependTo($('#standings tbody'));
                                } else {
                                    standings[row_at].row.insertAfter(standings[row_at-1].row);
                                }
                                row_at += 1;
                                next_row();
                            }
                        } else {
                            row_at += 1;
                            next_row();
                        }
                    }
                } ());
            }

            function Resolver(subs) {
                var sub_at = 0,
                    res_at = standings.length - 1,
                    res_problem = 0,
                    has_focused_team = false,
                    has_focused_problem = false,
                    is_playing = false;
                var all_buttons = [
                    'resolver_reset',
                    'resolver_playback_step',
                    'resolver_playback_play',
                    'resolver_playback_pause',
                    'resolver_playback_skip',
                    'resolver_resolve_step',
                    'resolver_resolve_play',
                    'resolver_resolve_pause' ];
                function disable_buttons() {
                    for (var i = 0; i < all_buttons.length; i++) {
                        get_cw_elem(all_buttons[i]).prop('disabled', true).css('color', 'gray');
                    }
                }
                function enable_buttons() {
                    var enable = {};

                    if (sub_at > 0 && !is_playing) enable['resolver_reset'] = true;
                    if (sub_at < subs.length) {
                        if (is_playing) {
                            enable['resolver_playback_pause'] = true;
                        } else {
                            enable['resolver_playback_step'] = true;
                            enable['resolver_playback_play'] = true;
                            enable['resolver_playback_skip'] = true;
                        }
                    }
                    if (sub_at >= subs.length && res_at >= 0) {
                        if (is_playing) {
                            enable['resolver_resolve_pause'] = true;
                        } else {
                            enable['resolver_resolve_step'] = true;
                            enable['resolver_resolve_play'] = true;
                        }
                    }

                    for (var i = 0; i < all_buttons.length; i++) {
                        var inc = enable.hasOwnProperty(all_buttons[i]);
                        get_cw_elem(all_buttons[i]).prop('disabled', !inc).css('color', inc ? 'black' : 'gray');
                    }
                }
                function get_timestep() {
                    return parseInt(get_cw_elem('resolver_resolve_timestep').val(), 10);
                }

                return {
                    reset: function () {
                        sub_at = 0;
                        res_at = standings.length - 1,
                        problem_at = 0;
                        $('#standings tr').removeClass('highlight');
                        $('#standings td').removeClass('resolve-problem');
                        has_focused_team = false;
                        has_focused_problem = false;
                        disable_buttons();
                        for (var i = 0; i < team_ids.length; i++) {
                            teams[team_ids[i]].reset();
                        }
                        update_standings(standings, false, enable_buttons);
                    },

                    playback_step: function () {
                        disable_buttons();
                        var sub = subs[sub_at];
                        var team = teams[sub['team']];
                        team.handle_submission(sub, false);
                        sub_at++;
                        update_standings(standings, true, enable_buttons);
                    },

                    playback_skip: function () {
                        disable_buttons();

                        while (sub_at < subs.length) {
                            var sub = subs[sub_at];
                            var team = teams[sub['team']];
                            team.handle_submission(sub, false);
                            sub_at++;
                        }
                        update_standings(standings, false, enable_buttons);
                    },

                    playback_play: function () {
                        is_playing = true;
                        var that = this,
                            running = true,
                            anim = false;
                        function end() {
                            if (anim) return;
                            that.playback_stop = null;
                            is_playing = false;
                            enable_buttons();
                        }
                        function time_to_next() {
                            // Note that 'time' is in minutes
                            var prev = sub_at === 0 ? 0 : subs[sub_at - 1]['time'];
                            return (subs[sub_at]['time'] - prev) * 60 * 1000 * get_time_multiplier();
                        }
                        var cur_timeout = null;
                        function process_sub() {
                            if (!running) {
                                end();
                                return;
                            }
                            var sub = subs[sub_at];
                            var team = teams[sub['team']];
                            team.handle_submission(sub, false);
                            sub_at++;
                            anim = true;
                            update_standings(standings, true, function () {
                                anim = false;
                                if (sub_at < subs.length && running) {
                                    cur_timeout = setTimeout(process_sub, time_to_next());
                                } else {
                                    end();
                                }
                            });
                        }

                        this.playback_pause = function () {
                            running = false;
                            disable_buttons();
                            clearTimeout(cur_timeout);
                            end();
                        };

                        cur_timeout = setTimeout(process_sub, time_to_next());
                        enable_buttons();
                    },

                    resolve_step: function (skip_buttons, callback) {
                        if (!skip_buttons) {
                            disable_buttons();
                        }

                        function done() {
                            if (!skip_buttons) {
                                enable_buttons();
                            }
                            if (callback) {
                                callback();
                            }
                        }
                        if (!has_focused_team) {
                            standings[res_at].row.addClass('highlight');
                            focus_on_element(standings[res_at].row);
                            has_focused_team = true;
                            done();
                        } else if (!has_focused_problem) {
                            while (res_problem < problems.length) {
                                if (standings[res_at].problems[problem_ids[res_problem]].pending.length > 0) {
                                    break;
                                }
                                res_problem++;
                            }
                            if (res_problem < problems.length) {
                                standings[res_at].problems[problem_ids[res_problem]].cell.addClass('resolve-problem');
                                has_focused_problem = true;
                            } else {
                                standings[res_at].row.removeClass('highlight');
                                res_at--;
                                res_problem = 0;
                                if (res_at >= 0) {
                                    standings[res_at].row.addClass('highlight');
                                    has_focused_team = true;
                                    has_focused_problem = false;
                                }
                            }
                            if (res_at >= 0) {
                                focus_on_element(standings[res_at].row);
                            }
                            done();
                        } else {
                            var problem = standings[res_at].problems[problem_ids[res_problem]];
                            console.log(problem);
                            var cur = problem.score;
                            var nxt = -1;
                            for (var j = 0; j < problem.pending.length; j++) {
                                if (problem.pending[j]['score'] > cur) {
                                    if (nxt < 0 || problem.pending[j]['score'] < nxt) {
                                        nxt = problem.pending[j]['score'];
                                    }
                                }
                            }
                            nxt = Math.max(nxt, 0);
                            console.log(nxt);

                            var rcnt = 0;
                            find_pending_loop:
                            //while (true) {
                            while (rcnt <= 1000) {
                                for (var j = 0; j < problem.pending.length; j++) {
                                    console.log('resolving');
                                    console.log(problem.pending);
                                    if (problem.pending[j]['score'] <= nxt || problem.pending[j]['score'] <= problem.score) {
                                        standings[res_at].handle_submission(problem.pending[j], true);
                                        rcnt++;
                                        continue find_pending_loop;
                                    }
                                }
                                break;
                            }
                            if (rcnt > 1000) {
                                problem.pending = [];
                            }

                            var old_row = standings[res_at].row,
                                old_cell = standings[res_at].problems[problem_ids[res_problem]].cell;
                            old_cell.removeClass('resolve-problem');
                            focus_on_element(standings[res_at].row);
                            update_standings(standings, true, function () {
                                old_row.removeClass('highlight');
                                has_focused_team = true;
                                has_focused_problem = false;
                                res_problem = 0;
                                standings[res_at].row.addClass('highlight');
                                // TODO: check if still the same team and submission?
                                done();
                            });
                        }
                    },

                    resolve_play: function (upto) {
                        if (res_at < upto) {
                            return;
                        }
                        is_playing = true;
                        var that = this,
                            running = true,
                            anim = false,
                            cur_timeout = null;
                        function end() {
                            if (anim) return;
                            that.resolve_stop = null;
                            is_playing = false;
                            enable_buttons();
                        }
                        function step() {
                            if (!running) {
                                end();
                                return;
                            }
                            anim = true;
                            that.resolve_step(true, function () {
                                anim = false;
                                if (res_at >= upto) {
                                    cur_timeout = setTimeout(step, get_timestep());
                                } else {
                                    end();
                                }
                            });
                        }
                        this.resolve_pause = function () {
                            running = false;
                            disable_buttons();
                            clearTimeout(cur_timeout);
                            end();
                        };
                        enable_buttons();
                        step();
                    }
                };
            }

            var header_row = table_header_tmpl({ all_captions: true, problems: data['problems'] });
            $('#standings thead').append(header_row);

            // Initialize problems
            var problems = data['problems'];
            var problem_ids = [];
            for (var i = 0; i < data['problems'].length; i++) {
                problem_ids.push(data['problems'][i]['id']);
            }

            // Initialize teams
            var teams = {},
                team_ids = [],
                standings = [];
            for (var i = 0; i < data['teams'].length; i++) {
                var team = new Team(data['teams'][i], problems);
                teams[team.id] = team;
                team_ids.push(team.id);
                $('#standings tbody').append(team.row);
                standings.push(team);
            }

            $('#standings tbody').append(table_header_tmpl({ all_captions: false, problems: data['problems'] }));

            // Initialize submissions
            var possible_subs = data['runs'];
            possible_subs.sort(function (a, b) {
                return a.time - b.time;
            });
            var subs = [];
            for (var i = 0; i < possible_subs.length; i++) {
                if (possible_subs[i]['status'] == 'New') continue;
                var team = teams[possible_subs[i]['team']];
                if (teams[possible_subs[i]['team']].handle_submission(possible_subs[i], true, true)) {
                    subs.push(possible_subs[i]);
                }
            }

            // Get ready to resolve!
            var resolver = Resolver(subs);
            resolver.reset();

            get_cw_elem('resolver_controls').submit(function () { return false; });
            get_cw_elem('resolver_reset').click(function () { resolver.reset(); });
            get_cw_elem('resolver_playback_step').click(function () { resolver.playback_step(); });
            get_cw_elem('resolver_playback_play').click(function () { resolver.playback_play(); });
            get_cw_elem('resolver_playback_pause').click(function () { resolver.playback_pause(); });
            get_cw_elem('resolver_playback_skip').click(function () { resolver.playback_skip(); });
            get_cw_elem('resolver_resolve_step').click(function () { resolver.resolve_step(); });
            get_cw_elem('resolver_resolve_play').click(function () {
                resolver.resolve_play(parseInt(get_cw_elem('resolver_resolve_play_upto').val(), 10));
            });
            get_cw_elem('resolver_resolve_pause').click(function () { resolver.resolve_pause(); });

            $(control_window.document).on('keydown', function (e) {
                var ids = [];
                if (e.keyCode === 39) {
                    // right arrow key
                    ids = ['resolver_playback_step', 'resolver_resolve_step'];
                } else if (e.keyCode === 32) {
                    // spacebar
                    ids = ['resolver_playback_play', 'resolver_playback_pause', 'resolver_resolve_play', 'resolver_resolve_pause'];
                }

                for (var i = 0; i < ids.length; i++) {
                    var elem = get_cw_elem(ids[i]);
                    if (!elem.prop('disabled')) {
                        elem.click();
                        break;
                    }
                }
            });

            // TODO: Figure out how to do this automatically
            update_cell_width();
        });
    }
});

