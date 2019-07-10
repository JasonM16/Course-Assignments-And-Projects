|||||||||||||||||||||||||||||  ASSIGNMENT 4  ||||||||||||||||||||||||||||||||||

									

||||||||||||||||||||||||||||||| QUESTION 7. ||||||||||||||||||||||||||||||||||| 
									
all_parts_of_c5 = project_first_of_2
						 (select_second_of_2 all_parts_of "c5")

|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



|||||||||||||||||||||||||||||| QUESTION 8. ||||||||||||||||||||||||||||||||||||

plastic_parts_of_c5 = project_first_of_2
			 (join_first_of_1_with_first_of_1 all_parts_of_c5 plastic)
			 
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



||||||||||||||||||||||||||||||| QUESTION 9. |||||||||||||||||||||||||||||||||||

all_parts_used_in_c5_but_not_in_c4 = all_parts_of_c5 -- all_parts_of_c4 

q9 = all_parts_of_c5 -- all_parts_of_c4 

all_parts_of_c4 = project_first_of_2
						 (select_second_of_2 all_parts_of "c4")

|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||



||||||||||||||||||||||||||||||| QUESTION 10.|||||||||||||||||||||||||||||||||||

q10
    = project_second_of_2 (select_first_of_2(used_together_with) "bolt")

parts_which_are_used_together_with_a_bolt 
	= project_second_of_2 (select_first_of_2(used_together_with) "bolt")

|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||









||||||||||||||||||||||||||||||||| TABLES ||||||||||||||||||||||||||||||||||||||
metal         = ["bolt", "nut", "washer", "bearing", "cog", "newnut"]
plastic       = ["gasket", "clip", "strap", "spacer", "newclip"]
part          = metal ++ plastic
compound_part = ["c1", "c2", "c3", "c4", "c5", "c6", "c7"]
component     = part ++ compound_part

component_of  
              = [("bolt",    "c1"),   ("nut", "c1"),   ("washer", "c1"),
                 ("bearing", "c2"),   ("cog", "c2"),   ("gasket", "c2"),
                 ("clip",    "c3"),   ("strap", "c3"), ("spacer", "c3"),
                 ("c1",      "c4"),   ("c3", "c4"),    ("c4", "c5"), 
                 ("c2",      "c5"),   ("c5", "c6")]
       
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||       


|||||||||||||||||||||||||||| PROJECTIONS ||||||||||||||||||||||||||||||||||||||

project_first_of_2 r = mkset[(x) | (x, y) <- r]

project_second_of_2 r = mkset[(y) | (x, y) <- r]

project_first_and_third_of_3 r = mkset[(x,z) | (x,y,z) <- r]

project_first_and_second_of_3 r = mkset[(x,y) | (x,y,z) <- r]

project_second_and_third_of_3 r = mkset[(y, z) | (x, y, z) <- r]
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


||||||||||||||||||||||||||||||| JOINS |||||||||||||||||||||||||||||||||||||||||
join_first_of_1_with_first_of_1 r s
      = [(x, y) | (x) <- r; (y) <- s; x = y]


join_first_of_2_with_first_of_2 r s
      = [(x, y, z) | (x, y) <- r; (a , z) <- s; x = a]


join_first_of_2_with_first_of_1 r s
      = [(x, y, z) | (x, y) <- r; z <- s; x = z]


join_first_of_1_with_first_of_2 r s
      = [(x, y) | (x) <- r; (a , y) <- s; x = a]


join_second_of_2_with_first_of_2 r s
      = [(x, y, z) | (x, y) <- r; (a , z) <- s; y = a]

|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


||||||||||||||||||||||||||||| SELECTS |||||||||||||||||||||||||||||||||||||||||
select_second_of_2 r key = [(x,y) | (x, y) <- r; y = key]

select_first_of_2 r key = [(x,y) | (x, y) <- r; x = key]


||||||||||||||||||||||| OPERATIONS AND FUNCTIONS ||||||||||||||||||||||||||||||
remove_reflexives r = [(a, b) | (a, b) <- r; a ~= b]

swap = map switch
       where switch (a, b) = (b, a)

union s t = s ++ (t --s)

intersection s t = s -- (s -- t)

make_transitive [] = []
make_transitive ((x, y):ps)
  = new_direct_paths ++
    [(a,c) | (a,b) <- mtps; (d,c) <- new_direct_paths; b = d] ++ mtps
    where
    mtps = make_transitive ps
    new_direct_paths = (x, y):[(x, b) | (n, b) <- mtps; n = y]

component_of_c5 
  = project_first_of_2
      (select_second_of_2 component_of "c5")

sub_component_of  
   = project_first_and_third_of_3
      (join_second_of_2_with_first_of_2 component_of 
                                                component_of)      
  
all_parts_of = make_transitive component_of

uses_component = swap component_of

used_together_with 
   = remove_reflexives 
      (project_second_and_third_of_3
        (join_first_of_2_with_first_of_2 uses_component 
	                                       uses_component))

|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

