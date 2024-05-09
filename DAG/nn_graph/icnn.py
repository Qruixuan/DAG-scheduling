import random

def generate_random_connection(layers):
    def recursive_generate(layer_idx, start_idx, current_path, connections):
        if layer_idx == len(layers):
            connections.append(list(current_path))
            return True  # 找到一种连接方式后立即返回

        for i in range(start_idx, len(layers[layer_idx])):
            current_path.append(layers[layer_idx][i])
            for j in range(max(0, layer_idx - 2), layer_idx):
                for k in range(len(layers[j])):
                    if layers[j][k] < layers[layer_idx][i]:
                        current_path.append(layers[j][k])
                        if recursive_generate(layer_idx + 1, i, current_path, connections):
                            return True  # 找到一种连接方式后立即返回
                        current_path.pop()
            current_path.pop()

        return False

    connections = []
    recursive_generate(0, 0, [], connections)
    return connections[0] if connections else None  # 返回找到的一种连接方式或者Non


def generate_connections(layer_sizes):
    connections = []
    node_indexs = []
    node_index = 0
    for layer_size in layer_sizes:
        node_in_layer = []
        for i in range(layer_size):
            node_in_layer.append(node_index)
            node_index += 1
        node_indexs.append(node_in_layer)

    connections = generate_random_connection(node_indexs)


    return connections

def write_connections_to_file(connections, filename, layer_sizes):
    numnodes = 0
    for i in layer_sizes:
        numnodes += i
    with open(filename, 'w') as f:
        f.write(f"{numnodes} {len(connections)}\n")
        for connection in connections:
            f.write(f"{connection[0]} {connection[1]}\n")



if __name__ == "__main__":
    layer_sizes =  [8,12,0,12,8]  # 每一层的节点数
    connections = generate_connections(layer_sizes)
    write_connections_to_file(connections, "i_network_connections10.txt", layer_sizes)
    delete_random_lines('i_network_connections10.txt')
    with open("network_connections10.txt", "r+") as file:
        # 读取文件内容
        lines = file.readlines()

        # 从第二行开始，在每行末尾加一个空格和一个随机数
        for i in range(1, len(lines)):
            # 生成随机数
            random_number = random.randint(0, 100)
            
            # 在每行末尾加入空格和随机数
            lines[i] = lines[i].rstrip('\n') + ' ' + str(random_number) + '\n'

        # 将修改后的内容写回文件
        file.seek(0)
        file.writelines(lines)