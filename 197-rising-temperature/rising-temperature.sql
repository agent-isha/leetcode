# Write your MySQL query statement below
SELECT w.id AS Id
FROM Weather w
JOIN Weather n
ON n.recordDate = w.recordDate - INTERVAL 1 DAY
WHERE n.temperature < w.temperature;

