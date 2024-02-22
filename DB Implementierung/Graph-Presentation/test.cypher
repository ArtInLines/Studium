




()                   // anonymous node
(x)                  // refer to node as 'x'
(:Person)            // filter by label
(p:Person)           // filter by label, refer to node as 'p'
(x:Person {age: 10}) // filter by label & property 'age'

(x)-[r]->(y)                  // 'x' has a relationship 'r' towards 'y'
(x:Person)-[r:USES]->(y:Lang) // Person 'x' uses language 'y'

CREATE (:Person {name: "Val", age: 20})                                               // create a single node
CREATE (:Person {name: "Val", age: 20})-[:USES {at_work: false}]->(:Lang {name: "C"}) // create several nodes, edges

MATCH (p:Person {name: "Val"})                           // Get all fitting nodes
MATCH (p:Person)-[r:USES]->(l:Lang {name: "C"})          // Get all fitting subgraphs
MATCH (p:Person)-[r:USES]->(l:Lang {name: "C"}) RETURN r // Return only what you want

MATCH (p:Person) WHERE p.age > 10 // WHERE like in SQL
MATCH (p:Person) ORDER BY p.age   // ORDER BY like in SQL
MATCH (p:Person) LIMIT 10         // Return 10 results at most

MERGE (p:Person {name: "Val"})  // Create only if node doesn't exist yet
ON CREATE SET p.age = 1
ON MATCH SET  p.age = p.age + 1

MATCH                           // MATCH combined with MERGE
	(p:Person {name: "Val"}),
	(l:Lang   {name: "C"})
MERGE (p)-[r:USES]->(l)


MATCH
	(p:Person {name: "Val"}),
	(l:Lang   {name: "Python"})
	p = shortestPath((p)-[:USES*]-(l))
WHERE all(r in relationships(p) r.at_work = true)
RETURN p






