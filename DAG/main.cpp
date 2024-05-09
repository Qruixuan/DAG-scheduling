#include <iostream>
#include <time.h>
#include "Graph.h"
#include "GraphKit.h"

int main(int argc, char const *argv[])
{
    int n, m;
    std::cin >> n >> m;
    Graph d(n, m);
    std::vector<std::vector<int>> mat;
    mat.assign(n, std::vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        if(mat[u][v]==0){
            d.addEdge(u, v, w);
            mat[u][v]=1;
        }
        // d.addEdge(u, v, w);
    }

    GraphKit k(d);
    k.runMaxcut();
    std::cout<<"memory using maxtopcut: "<<k.getmaxcutMemory()<<std::endl;
    k.runDfs();
    std::cout<<"memory using dfs: "<<k.getDfsMemory()<<std::endl;
    std::cout<<"time using dfs: "<<k.getDfsTime()<<std::endl;
    k.runIdfs();
    std::cout<<"memory using idfs: "<<k.getIdfsMemory()<<std::endl;
    std::cout<<"time using idfs: "<<k.getIdfsTime()<<std::endl;
    k.runDp(false, -1);
    std::cout<<"memory using dp: "<<k.getDpMemory()<<std::endl;
    std::cout<<"time using dp: "<<k.getDpTime()<<std::endl;
    k.runDp(false, 20);
    std::cout<<"memory using modified dp: "<<k.getDpMemory()<<std::endl;
    std::cout<<"time using modified dp: "<<k.getDpTime()<<std::endl;
    // k.runDfs();
    // std::cout<<"memory using dfs: "<<k.getDfsMemory()<<std::endl;
    // k.printDfsSequence();
    // k.runMaxcut();
    // for(int i : k.topological_cut){
    //     std::cout<<i<< " ";
    // }
    // std::cout<<std::endl;
    // std::cout<<"memory using maxtopcut: "<<k.getmaxcutMemory()<<std::endl;
    // k.runDp(false, 20);
    // std::cout<<"memory using dp: "<<k.getDpMemory()<<std::endl;
    // k.printDpSequence();
    // std::vector<int> Dpsequence = k.getDpSequence();
    
    // std::vector<int> add_edges = k.RESPECTORDER(Dpsequence);

    // for(int i : add_edges){
    //     std::cout<<Dpsequence[i]<< " ";
    // }
    // std::cout<<std::endl;
    // d.addEdge(Dpsequence[add_edges[0]],Dpsequence[add_edges[1]],0);
    // GraphKit k2(d);
    // k2.runMaxcut();
    // for(int i : k2.topological_cut){
    //     std::cout<<i<< " ";
    // }
    // std::cout<<std::endl;
    // std::cout<<"memory using maxtopcut: "<<k2.getmaxcutMemory()<<std::endl;
    
    // add_edges = k2.RESPECTORDER(Dpsequence);

    // for(int i : add_edges){
    //     std::cout<<Dpsequence[i]<< " ";
    // }
    // std::cout<<std::endl;
    // d.addEdge(Dpsequence[add_edges[0]],Dpsequence[add_edges[1]],0);
    // GraphKit k3(d);
    // k3.runMaxcut();
    // std::cout<<"memory using maxtopcut: "<<k3.getmaxcutMemory()<<std::endl;
    
}