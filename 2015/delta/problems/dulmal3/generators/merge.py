import itertools

words = [
    # 'banani',
    # 'bolti',
    # 'belja',

    # 'hjalp',
    # 'help',
    # 'hallo',
    # 'hello',

    # 'forrita',
    # 'ferseti',
    # 'freta',
    # 'frabaert',
    # 'flott',
    # 'faggi',
    # 'fret',
    # 'fardu',
    # 'faranlegt',
    # 'frestur',
    # 'fartegi',

    # 'falleg',
    # 'forljot',

    # 'like',
    # 'ljot',
    # 'laus',
]

# b___ao__n_l_a__tn___i_
# b__eaol_njl_a__tn___i
# b__eaol_njl_a__tn___i_
# h_jaaelepll_o_ll____op

# b____aoe__n_l_la__t_nj__ii__a_
# h________jaee_____a_l_l_l__l__l__l__p___o___o

# f__o_lr__ro_i__t__a_t
# l___ij__k_o_e__t
# l______ija____k_o_u__e__t__s

length = 1
while True:

    valid = [ [] for w in words ]

    for j in range(1, length):
        cnt = 0
        for i in range(0, length, j):
            cnt += 1

        for i in range(len(words)):
            if len(words[i]) == cnt:
                valid[i].append(j)

    for ass in itertools.product(*valid):
        s = ['_']*length
        ok = True
        for i in range(len(words)):

            w = words[i]
            for j in range(len(w)):
                at = j*ass[i]
                if s[at] == '_' or s[at] == w[j]:
                    s[at] = w[j]
                else:
                    ok = False
                    break

            if not ok:
                break

        if ok:
            print(''.join(s))


    length += 1

