|| INDIVIDUAL ASSIGNMENT #4 DUE Group lab on Thursday 23rd 
|| October 2014 or Friday 24th October. YOU WILL BE ASKED TO 
|| DEMONSTRATE YOUR PROGRAM AT THE GROUP LABS.

|| THIS ASSIGNMENT IS WORTH TWICE THE MARKS OF OTHER ASSIGNMENTS
|| 
|| THIS FILE IS EXECUTABLE SO THAT YOU CAN EXPERIMENT WITH IT
|| You can get it by going to the course website
|| clicking on "individual assignment #4" THEN copy
|| and paste the contents to an empty file called
|| assig4.m that you have just opened using a text editor
|| THEN TRANSFER the file assig4.m
|| to server and then use Miranda to compile and run.
|| DO NOT just save the file from the website as it
|| will add HTML code at the top and end of the file 
||
|| PART I
|| The following is the data for this assignment

metal     = ["bolt", "nut", "washer", "bearing", "cog", "newnut"]
plastic   = ["gasket", "clip", "strap", "spacer", "newclip"]
part          = metal ++ plastic
compound_part = ["c1", "c2", "c3", "c4", "c5", "c6", "c7"]
component     = part ++ compound_part

component_of  
    = [("bolt",    "c1"),   ("nut", "c1"),   ("washer", "c1"),
       ("bearing", "c2"),   ("cog", "c2"),   ("gasket", "c2"),
       ("clip",    "c3"),   ("strap", "c3"), ("spacer", "c3"),
       ("c1",      "c4"),   ("c3", "c4"),    ("c4", "c5"), 
       ("c2",      "c5"),   ("c5", "c6")]
	   
|| QUESTION 1. DRAW 6 TABLES REPRESENTING EACH OF THE 
|| RELATIONS ABOVE YOU CAN MISS OUT THE QUOTATION MARKS

|| PART II
|| The following are example programs for relational algebra 
|| You will need to add some operators similar to these
	    
project_first_of_2 r = mkset[(x) | (x, y) <- r]


|| QUESTION 2. DRAW THE TABLE THAT YOU GET FROM:
||  
||          project_second_of_two   component_of


project_second_of_2 r = mkset[(y) | (x, y) <- r]

project_first_and_third_of_3 r = mkset[(x,z) | (x,y,z) <- r]

project_second_and_third_of_3 r = mkset[(y, z) | (x, y, z) <- r]
join_first_of_2_with_first_of_2 r s
      = [(x, y, z) | (x, y) <- r; (a , z) <- s; x = a]

join_first_of_1_with_first_of_2 r s
      = [(x, y) | (x) <- r; (a , y) <- s; x = a]


join_second_of_2_with_first_of_2 r s
      = [(x, y, z) | (x, y) <- r; (a , z) <- s; y = a]

|| QUESTION 3. DRAW THE TABLE THAT YOU GET FROM:
||
|| join_second_of_2_with_first_of_2  component_of component_of


select_second_of_2 r key = [(x,y) | (x, y) <- r; y = key]

select_first_of_2 r key = [(x,y) | (x, y) <- r; x = key]

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

|| PART II
|| Now consider the following new relations that can be defined
|| in terms of the relations above. 

component_of_c5 
  = project_first_of_2
      (select_second_of_2 component_of "c5")

|| QUESTION 4. DRAW THE TABLE  component_of_c5

sub_component_of  
   = project_first_and_third_of_3
      (join_second_of_2_with_first_of_2 component_of 
                                                component_of)      
|| 
|| QUESTION 5. DRAW THE TABLE sub_component_of
||
  
all_parts_of = make_transitive component_of

uses_component = swap component_of

used_together_with 
   = remove_reflexives 
      (project_second_and_third_of_3
        (join_first_of_2_with_first_of_2 uses_component 
	                                       uses_component))

|| QUESTION 6. DRAW THE TABLE THAT YOU GET FROM:
||
||    all_parts_of  


|| PART III
||
|| Now write relational algebra expressions 
|| for the following relations
|| QUESTION 7. all_parts_of_c5  Hint define like 
||      component_of_c5 but use the all_parts_of relation.
|| QUESTION 8. plastic_parts_of_c5 
|| QUESTION 9. all_parts_used_in_c5_but_not_in_c4
|| QUESTION 10. parts_which_are_used_together_with_a_bolt
