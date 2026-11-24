//DFS, BFS, Dijkstra and A are all the same loop. All that changes is the container holding the nodes I still need to visit list.

//DFS - stack (LIFO)
//BFS - Queue (FIFO)
//Dijkstra - priority queue ordered by distance so far
//A - Priority queue ordered by distance so far + estimate of distance left



/*
	All shared a skeleton that is:

		put start node in container
		while container isn't empty take one node out
		skip it if you have finished
		look at each neighbour in adj list row and decide whether to add it 

*/



/*
	Write the order of nodes visited down on paper first so that you can check the program prints correctly 
*/