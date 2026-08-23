# Write your MySQL query statement below
select max(salary) as SecondHighestSalary
FROM (
    SELECT 
        salary,
        dense_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM Employee 
) AS temp
where rnk=2
