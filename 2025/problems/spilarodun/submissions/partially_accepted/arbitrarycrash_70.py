flk, cnt = {}, 0
for s in ["Venjulegt", "Ahrifa", "Bodunar", "Samruna", "Samstillt", "Thaeo", "Penduls", "Tengis"]:
    flk["Skrimsli - " + s] = cnt
    cnt += 1
for s in ["Venjulegur", "Bunadar", "Svida", "Samfelldur", "Bodunar", "Hradur"]:
    flk["Galdur - " + s] = cnt
    cnt += 1
for s in ["Venjuleg", "Samfelld", "Mot"]:
    flk["Gildra - " + s] = cnt
    cnt += 1
flk["Annad"] = cnt
cards = []
n = int(input())
for _ in range(n):
    nam, idnum, kind, date = input().strip().split(", ")
    cards.append((nam, int(idnum), flk[kind], date))
ords = list(input().strip().split())
word2ind = {"nafn": 0, "id": 1, "flokkur": 2, "dagsetning": 3}
assert ords != ["flokkur", "dagsetning", "nafn", "id"]
for w in ords[::-1]:
    cards.sort(key=lambda x: x[word2ind[w]])
for card in cards:
    print(card[0])
