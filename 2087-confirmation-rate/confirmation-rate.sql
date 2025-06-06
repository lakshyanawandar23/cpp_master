# Write your MySQL query statement below
select signups.user_id,round(if(count(confirmations.action)=0,0,SUM(confirmations.action='confirmed')/count(*)),2) as confirmation_rate from signups left join confirmations on signups.user_id=confirmations.user_id
 group by signups.user_id;