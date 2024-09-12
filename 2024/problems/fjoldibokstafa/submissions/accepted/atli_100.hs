import Data.Char

main = do
    line <- getLine
    putStrLn . show . length $ filter Data.Char.isAlpha line
