select id1 as id, count(id2) as num from
(
    select requester_id as id1, accepter_id as id2 from request_accepted
    union all
    select accepter_id as id1, requester_id as id2 from request_accepted
) tmp
group by id
order by num desc limit 1