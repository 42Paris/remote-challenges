
rotn :: String -> Int -> String
rotn xs n = let len = length xs in take len . drop n . cycle $ xs

ft_necklace :: String -> String -> Int
ft_necklace s1 s2 = if length s1 /= length s2 then 0 else
  if all (/=s1) $ (rotn s2) <$> [0..(length s2)] then 0 else 1

main :: IO ()
main = do
  let xs = ["nicole", "nicole", "nicole", "aabaaaaabaab", "abc", "xxyyy", "xyxxz", "x", "x", "x", ""]
  let ys = ["icolen", "lenico", "coneli", "aabaabaabaaa", "cba", "xxxyy", "xxyxz", "x", "xx", "", ""]
  mapM_ (\(s1,s2) -> putStrLn . show $ ft_necklace s1 s2) $ zip xs ys