# Write your MySQL query statement below
select unique_id,name
FROM
Employees as e
left join
EmployeeUNI as eu
on 
e.id=eu.id
