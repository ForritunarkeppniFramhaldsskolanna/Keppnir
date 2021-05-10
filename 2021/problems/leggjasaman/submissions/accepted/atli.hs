main = do
    arnar <- getLine
    hannes <- getLine
    putStrLn . show $ (read arnar) + (read hannes)

