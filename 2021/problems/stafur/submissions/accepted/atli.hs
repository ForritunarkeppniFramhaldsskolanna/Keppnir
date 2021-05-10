iscons :: Char -> String
iscons c
    | c == 'Y' = "Kannski"
    | c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' = "Jebb"
    | otherwise = "Neibb"

main = do
    stafur <- getLine
    putStrLn . iscons $ stafur !! 0
