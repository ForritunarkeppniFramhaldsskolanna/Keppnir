import qualified Control.Monad as CM

swapElementsAt :: Int -> Int -> [String] -> [String]
swapElementsAt a b list = list1 ++ [list !! b] ++ list2 ++ [list !! a] ++ list3
    where   list1 = take a list;
            list2 = drop (succ a) (take b list);
            list3 = drop (succ b) list

main = do
    n <- getLine 
    names <- CM.replicateM (read n) getLine
    let ind = mod 12 $ read n
    if ind == 0
        then putStrLn . unlines $ names
        else putStrLn . unlines $ swapElementsAt 0 ind names

