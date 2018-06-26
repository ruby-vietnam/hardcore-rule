## Problem 1

## Problem 2
```haskell
module Codewars.Kata.Reduction where
import Codewars.Kata.Reduction.Direction

-- data Direction = North | East | West | South deriving (Eq)

dirReduce :: [Direction] -> [Direction]
dirReduce = foldr reduce []

reduce North (South:xs) = xs
reduce South (North:xs) = xs
reduce East (West:xs) = xs
reduce West (East:xs) = xs
reduce x xs = x:xs
```
## Problem 3

## Problem 4
```haskell
module Codewars.Kata.SumByFactors where
import Data.List

factor :: Integer -> Integer -> [Integer] -> [Integer]
factor p n ps
  | n == 1 = ps
  | mod n p == 0 = factor p (div n p) (p:ps)
  | n < p * p = factor n n ps
  | otherwise = factor (p + 1) n ps

primeFactors :: Integer -> [Integer]
primeFactors n = factor 2 (abs n) []

primes :: [Integer] -> [Integer]
primes ns = sort (dedup (concat (map primeFactors ns)))

dedup :: Eq a => [a] -> [a]
dedup xs = dedup' xs []
  where
    dedup' [] _ = []
    dedup' (x:xs) ls
      | elem x ls = dedup' xs ls
      | otherwise = x : dedup' xs (x:ls)

sumMod :: Integer -> [Integer] -> Integer
sumMod p ns = sum (filter (\n -> mod n p == 0) ns)

sumOfDivided :: [Integer] -> [(Integer, Integer)]
sumOfDivided ns = map (\p -> (p, sumMod p ns)) (primes ns)
```
