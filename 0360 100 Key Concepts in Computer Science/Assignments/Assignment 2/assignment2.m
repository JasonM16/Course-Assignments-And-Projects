|| 60-100 Individual Assignment #2
|| Jason Choquette
|| ID: 104337378
|| Sep. 19/14

p1 = [[1, 2], [2, 3]]

p2 = p1!1

p3 = map(^3)  

p4 = foldr (+) 0

p5 x y = x, if x > 0
       = y, otherwise 

p6 x y = x, if x!0 > y!0
       = y, otherwise

p7 0 = True
p7 1 = False
p7 2 = False
p7 x = p7 (x-3) 

p8 x y = or (map (=y) x)  

p9 x = p4 (p3 x)

p10 x y = [(x,y) | x <- x; y <- y; x > y ]   









