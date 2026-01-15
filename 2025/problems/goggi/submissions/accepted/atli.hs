verdict :: Int -> Int -> String
verdict x y
    | x > y = ">"
    | x < y = "<"
    | otherwise = "Goggi svangur!"

main = do
    l <- getLine
    let [x, _, y] = map read $ words l
    putStrLn $ verdict x y
