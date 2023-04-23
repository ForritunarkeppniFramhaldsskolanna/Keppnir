#!/usr/bin/python3
# First attempt gave a runtime error on sample 1, reported nothing but the error and almost this came out
# Second attempt gave runtime error on sample 2, it described how to fix, I said thatback and it output this code
import sys

def process_data(n, k, companies, m, photos):
    parked = {}
    for i in range(k):
        for j in range(companies[i][1]):
            parked[companies[i][2][j]] = (i, 0)
    
    for i in range(m):
        if photos[i] in parked and parked[photos[i]] is not None:
            company, count = parked[photos[i]]
            if count < companies[company][0]:
                parked[photos[i]] = (company, count+1)
            else:
                parked[photos[i]] = None
        else:
            parked[photos[i]] = None

    illegally_parked = [k for k, v in parked.items() if v is None]
    illegally_parked.sort()
    return len(illegally_parked), illegally_parked

if __name__ == '__main__':
    n, k = map(int, input().strip().split())
    companies = []
    for i in range(k):
        n_i, m_i = map(int, input().strip().split())
        plates = [input().strip() for _ in range(m_i)]
        companies.append((n_i, m_i, plates))
    m = int(input().strip())
    photos = [input().strip() for _ in range(m)]
    result = process_data(n, k, companies, m, photos)
    print(result[0])
    print(*result[1], sep='\n')
