import subprocess
import sys
import os

pdfs = [
    ('fk_2015_sinus_fyrir_hadegi', 'Sínus deild - Fyrir hádegi', [
            '../beta/problems/dotplot',
            '../beta/problems/dulmal2',
            '../beta/problems/margfeldi2',
            '../beta/problems/pi',
            '../beta/problems/zencoding',
            '../beta/problems/selfdescription',
            '../beta/problems/planets',
            '../beta/problems/dulmal3',
            '../beta/problems/p2048',
            '../beta/problems/divisible11',
            '../beta/problems/dulmal4',
    ]),

    ('fk_2015_sinus_eftir_hadegi', 'Sínus deild - Eftir hádegi', [
            '../beta/problems/lucky',
            '../beta/problems/demantar',
            '../beta/problems/breakingbad',
            '../beta/problems/debruijn',
            '../beta/problems/brot',
            '../beta/problems/backup',
            '../beta/problems/tiskulegarkyr',
            '../beta/problems/jonspaejo',
            '../beta/problems/reversibleprimes',
            '../beta/problems/guess',
    ]),

    ('fk_2015_pi_fyrir_hadegi', 'Pí deild - Fyrir hádegi', [
            '../delta/problems/skrifapi',
            '../delta/problems/skrifapi2',
            '../delta/problems/margfoldun',
            '../delta/problems/logri',
            '../delta/problems/dulmal',
            '../delta/problems/dulmal2',
            '../delta/problems/dulmal3',
            '../delta/problems/autoderivative',
            '../delta/problems/dotplot',
            '../delta/problems/brot',
            '../delta/problems/debruijn2',
            '../delta/problems/tr',
            '../delta/problems/margfeldi2',
            '../delta/problems/p2048',
            '../delta/problems/lucky2',
            '../delta/problems/selfdescription',
    ]),

    ('fk_2015_pi_eftir_hadegi', 'Pí deild - Eftir hádegi', [
            '../delta/problems/pi',
            '../delta/problems/summa',
            '../delta/problems/haed',
            '../delta/problems/demantar',
            '../delta/problems/evilodious2',
            '../delta/problems/divisible11',
            '../delta/problems/freqletter',
            '../delta/problems/asdfgh',
            '../delta/problems/planets',
            '../delta/problems/countintegers',
            '../delta/problems/guess2',
            '../delta/problems/reversibleprimes',
            '../delta/problems/backup',
            '../delta/problems/speglasalur2',
            '../delta/problems/gcd',
            '../delta/problems/dulmal4',
    ]),
]

def gen_title_page(name, title):
    with open(name + '_front.tex', 'w') as f:
        f.write(r'''\documentclass{article}
\usepackage[utf8]{inputenc}
\usepackage[T1]{fontenc}
\title{{\Large Forritunarkeppni framhaldsskólanna 2015} \\ \vspace{10pt} {\LARGE %(title)s} \vspace{-10pt}}
\date{14. mars 2015}
\begin{document}
\maketitle
\thispagestyle{empty}
\end{document}
''' % {'name': name, 'title': title})

    p = subprocess.Popen(['pdflatex', name+'_front.tex'])
    p.wait()
    os.unlink(name + '_front.tex')
    return name + '_front.pdf'

for name, title, problems in pdfs:
    print('Generating %s' % title)

    pages = [ gen_title_page(name, title) ]
    for problem in problems:
        p = subprocess.Popen(['/home/bjarki/projects/problemtools/problem2pdf.py', problem])
        p.wait()
        pages.append(os.path.basename(problem) + '.pdf')


    p = subprocess.Popen([ 'pdfunite' ] + pages + [ name + '.pdf' ])
    p.wait()

    for pg in pages:
        os.unlink(pg)

