const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let n = -1n;
let m;
let k;

let arr = []
rl.on('line', (line) => {
    if (n == -1n) {
        n = BigInt(line.split(" ")[0])
        m = BigInt(line.split(" ")[1])
        k = BigInt(line.split(" ")[2])
    }
    else if (n != 0n) {
        arr.push(BigInt(line.split(" ")[1]))
        n -= 1n;
        if (n == 0) {
            let x;
            if (m == 0) x = 100000000
            else x = (k + m - 1n) / m;

            arr = arr.sort((a, b) => (a < b ? -1 : a > b ? 1 : 0));
            let cards = 0n;
            let ans = 0n;


            for (let i = 0; i < BigInt(arr.length); i++) {
                arr[i] -= cards;
                if (BigInt(arr.length) - BigInt(i) >= x) {
                    cards += arr[i];
                } else {
                    ans += arr[i] * m;
                }
            }
            console.log(String(cards), String(ans + cards * k));
        }
    }
});
