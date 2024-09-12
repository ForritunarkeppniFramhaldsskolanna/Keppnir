main = do
    inp <- getLine
    putStrLn . reverse $ foldl (\acc x -> if x == head acc then acc else x : acc) [head inp] (tail inp)
