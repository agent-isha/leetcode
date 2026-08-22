# Write your MySQL query statement below
WITH temp AS (
    SELECT *,
           COUNT(*) OVER(PARTITION BY tiv_2015) AS cnt_2015,
           COUNT(*) OVER(PARTITION BY lat, lon) AS cnt_location
    FROM Insurance
)

SELECT ROUND(
    SUM(
        CASE
            WHEN cnt_2015 > 1 AND cnt_location = 1
            THEN tiv_2016
            ELSE 0
        END
    ), 2
) AS tiv_2016
FROM temp;
