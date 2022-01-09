# Network-Metro

---

This code get us the minimum path for a bus displacement in a Metro network. The buses and nodes can be of different colors, then the bus can or not stop in one station (node) or not.



## Documentation

---

The documentation was made with Doxygen. It is not necessary to install the tool, but it is better in order to see it better. To open the files and check the comments is enough.

If Doxygen was installed then execute the commands to check it in the browser

```bash
doxygen
browser doc/html/index.html
```



## Data file

---

The data file is located in the `dat` folder, and it's name is `network.csv` (The other files are test data files. Don't modify). This is a CSV file with comma (,) delimiter. The structure of the file consists of tow parts. The first part is the node with its attribute (color), and the second one the edges. So the structure, if wanted to be modify, must keep:

| **Nodo**  | **Color** |
| --------- | --------- |
| Node1     | Color1    |
| Node2     |           |
| Node3     | Color2    |
| Node4     | Color1    |
| ...       | ...       |
|           |           |
| **Nodo1** | **Nodo2** |
| Node1     | Node2     |
| Node1     | Node3     |
| Node4     | Node3     |
| ...       | ...       |

The graph is undirected, so is not neccesary to write to times the same edge. The color is not a mandatory value. If it is not define, then the default value is "NOCOLOR".

## Execution process

---

The execution is done with the `script.sh` file. This file receive multiple arguments:

- **filename (f)**: Which corresponds to the name of the file where the data is. This is not a mandatory argument. The default value is "dat/network.csv".

- **Init node (i)**: Is the node (station) where the bus starts its route. This is a mandatory argument.

- **End node (e)**: Is the node (station) where the bus finishes its route. This is a mandatory argument.

- **Color bus (c)**: The type of bus we are going to take. This is not a mandatory argument and its default value is "NOCOLOR".

- **Test boolean (t)**: This argument say to the program if we want to execute the tests. The possible values are "Yes" or "No". "No" is the default value.

The command line for the correct execution is this:

```bash
bash script.sh -f filename -i init_node -e end_node -c color -t No
```

The arguments can be permuted in any order. 

In the special case of **testing** there is only needed to do the next command line

```bash
bash script.sh -t Yes
```
