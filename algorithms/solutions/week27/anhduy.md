# Sum by Factors

```haskell
module Codewars.Kata.SumByFactors where

import Data.List (sort)

sumOfDivided :: [Integer] -> [(Integer, Integer)]
sumOfDivided xs = foldr (sumOfFactor xs) [] (sort . concatMap (factors . abs) $ xs)

sumOfFactor :: [Integer] -> Integer -> [(Integer, Integer)] -> [(Integer, Integer)]
sumOfFactor xs n [] = [(n, fsum n xs)]
sumOfFactor xs n ys@((k, _):ys') 
  | n == k = ys
  | otherwise = (n, fsum n xs) : ys
    
fsum :: Integer -> [Integer] -> Integer
fsum n = sum . filter (\x -> x `mod` n == 0)

primes :: [Integer]
primes = 2 : filter isPrime [3, 5..]

isPrime :: Integer -> Bool
isPrime n = head (factors n) == n

factors :: Integer -> [Integer]
factors n = f n primes where
  f x (p:ps')
    | x < 2 = []
    | x < p ^ 2 = [x]
    | x `mod` p == 0 = p : f (fullDiv x p) ps'
    | otherwise = f x ps'

fullDiv :: Integer -> Integer -> Integer
fullDiv x y 
  | x `mod` y == 0 = fullDiv (x `div` y) y
  | otherwise = x
```

# Directions Reduction

```haskell
module Codewars.Kata.Reduction where
import Codewars.Kata.Reduction.Direction

-- data Direction = North | East | West | South deriving (Eq)

dirReduce :: [Direction] -> [Direction]
dirReduce = foldr reduce [] 

reduce :: Direction -> [Direction] -> [Direction]
reduce South (North:xs) = xs
reduce West (East:xs) = xs
reduce North (South:xs) = xs
reduce East (West:xs) = xs
reduce direction xs = direction : xs
```
