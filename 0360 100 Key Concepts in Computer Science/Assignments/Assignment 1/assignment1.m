|| 60-100 Individual Assignment #1
|| Jason Choquette
|| ID: 104337378
|| Sep. 09/14

p1 = 2014 - 1979

p2 = "Jason Choquette"

p3 x = x * 2

p4 x y = x, if x >= y
       = y, if x < y   
			
p5 = map(*2)

p6 x = x!0

p7 = foldr (*) 1

p8 0 = 1
p8 n = n * p8(n-1)

p9 xs ys = [x | x <- xs; member ys x]

p10 [] = []
p10 (a:x) = p10 x ++ [a]

p11 0 = True
p11 1 = False
p11 x = P11 (x-2)

p12 = foldr (+) 0 . map mysum
      where
      mysum (x,y) = x