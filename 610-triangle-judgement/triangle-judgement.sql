# Write your MySQL query statement below
select x,y,z,(case when(t.x+t.y)>t.z and (t.y+t.z)>t.x and (t.x+t.z)>t.y and x>0 and y>0 and z>0 then "Yes" else "No" end )as triangle
from Triangle as t
