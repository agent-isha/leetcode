# Write your MySQL query statement below
select contest_id,round((count(*)/(select count(*) from Users))*100,2) as percentage
from Users as u
left join
Register as r
on u.user_id=r.user_id
where contest_id is not null
group by contest_id
order by percentage desc,contest_id asc;







