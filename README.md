# CplusplusProgram
cs305
1.What was the problem you were solving in the projects for this course?
The project involved developing a software application to manage course information efficiently, including operations to load course data from a file, display the list of courses, display details of a specific course, and exit the application. The challenge lay in implementing these functionalities using three different data structures: Vector, Hash Table, and Binary Search Tree (BST), to understand their strengths and weaknesses in various scenarios.

2. How did you approach the problem? Consider why data structures are important to understand.
I approached the problem by first breaking down the requirements into smaller, manageable functions, such as loading data, printing course lists, and printing specific course details. For each of these functions, I implemented algorithms suited to the characteristics of the three chosen data structures.

Understanding data structures is crucial because they are foundational to creating efficient algorithms. Different data structures offer various advantages and disadvantages depending on the use case. For instance, Hash Tables provide average O(1) time complexity for insertion and search operations, making them ideal for scenarios where quick data retrieval is essential. On the other hand, BSTs maintain data in a sorted order, allowing for efficient in-order traversal and search operations, albeit potentially suffering from unbalanced trees. Vectors are simple and provide fast access to elements but can be inefficient for frequent insertions or deletions.

3. How did you overcome any roadblocks you encountered while going through the activities or project?
When faced with roadblocks, such as handling errors in file input or dealing with unbalanced BSTs, I conducted research to better understand the problem and identify potential solutions. For instance, I learned about balancing techniques for BSTs to ensure efficient operation regardless of the input order. Additionally, I implemented error checking and handling mechanisms to ensure the program could gracefully manage incorrect inputs or formatting issues.

4. How has your work on this project expanded your approach to designing software and developing programs?
This project has broadened my understanding of the importance of choosing the right data structure for a given problem, as it has a significant impact on the efficiency and effectiveness of the software. I’ve learned to consider not just the functional requirements but also the performance implications of my design choices. This has led me to adopt a more holistic approach to software design, taking into account both the immediate requirements and potential future needs or changes.

5. How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
Working on this project has reinforced the importance of writing clean, modular code. By breaking down the problem into smaller functions and ensuring each function has a single responsibility, the code is more readable and easier to maintain. Furthermore, I’ve learned to document my code thoroughly, explaining the purpose of each function and the logic behind critical sections of the code. This practice ensures that others (or myself at a later date) can quickly understand and modify the code if necessary.

In terms of adaptability, designing the software with modularity in mind ensures that it can be easily extended or modified in the future. For example, if a new data structure needed to be added or an existing one replaced, the impact on the rest of the code would be minimal due to the modular design. 
