# Write your MySQL query statement below
WITH BoardingQueue AS (
    SELECT 
        person_name,
        turn,
        SUM(weight) OVER (ORDER BY turn) AS running_weight
    FROM Queue
)
SELECT person_name
FROM BoardingQueue
WHERE running_weight <= 1000
ORDER BY turn DESC
LIMIT 1;