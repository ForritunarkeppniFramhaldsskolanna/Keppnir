import qualified Control.Monad as CM
import Data.Containers.ListUtils (nubInt)
import qualified Data.ByteString.Char8 as C

readChar8 :: IO [Int]
readChar8 = map parse . C.words <$> C.getLine
  where parse s = let Just (n, _) = C.readInt s in n

main = do
    bounds <- readChar8
    puzzles <- (map tail) <$> CM.replicateM (bounds !! 0) readChar8 :: IO [[Int]]
    let pieces = foldl (\x y -> nubInt (x ++ y)) [] puzzles
    if length pieces == bounds !! 1
        then putStrLn "Jebb"
        else putStrLn "Neibb"

