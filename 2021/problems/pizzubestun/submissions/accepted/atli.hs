import qualified Control.Monad as CM
import qualified Data.List as DL

chunkify :: Int -> [a] -> [[a]]
chunkify _ [] = []
chunkify n xs = as : chunkify n bs
    where (as, bs) = splitAt n xs

main = do
    n <- getLine
    lst <- CM.replicateM (read n) getLine
    let cst = DL.reverse . DL.sort $ map (read . last . words) lst
    putStrLn . show . sum . (map maximum) $ chunkify 2 cst

