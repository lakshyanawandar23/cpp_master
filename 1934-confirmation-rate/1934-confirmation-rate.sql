# Write your MySQL query statement below
 Select S.user_id,round(avg(if(C.action = 'confirmed', 1, 0)), 2) as Confirmation_rate  from Signups as S LEFT JOIN Confirmations as C ON
  S.user_id=C.user_id
  group by S.user_id;