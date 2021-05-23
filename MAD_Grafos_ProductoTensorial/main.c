#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    ///DATOS WIKIPEDIA
    int n1 = 5;
    int n2 = 4;
    char G1[5] = "12345";
    char G2[4] = "6789";

    int CantCaminos = 8;
    char edges[8][2] ={
        "12","23","24","45","35",
        "67","78","79"
    };


    /**
    ///Datos propios
    int n1 = 5;
    int n2 = 2;
    char G1[5] = "12345";
    char G2[2] = "67";

    int CantCaminos = 7;
    char edges[7][2] ={
        "12","13","23","34","45","25",
        "67"
    };
    24/2 caminos  (al quitar los repetidos)
    12 = 6*1 *2
        */



    char productos[n1*n2][2];
    int valorFrom0[n1*n2];

    int pos=0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            productos[pos][0] = G1[i];///6
            productos[pos][1] = G2[j];///5
            char a = productos[pos][0];
            char c = productos[pos][1];
            printf("G.add_node('%c%c') #%d\n", a,c,i*4+j);
            valorFrom0[pos] = i*5+j;
            //printf("G.add_node('%d') \n",valorFrom0[pos] );
            pos++;
        }
    }

    pos=0;
    for(int i=0;i<n1*n2;i++)
    {
        for(int j=0;j<n1*n2;j++)
        {

            char a = productos[i][0];
            char c = productos[i][1];
            char b = productos[j][0];
            char d = productos[j][1];
            ///Ahora compruebo si existe camino entre esos dos! segund los caminos previos
            int cond1 =0;
            int cond2 =0;
            for(int k=0;k<CantCaminos;k++)
            {
                if(a == edges[k][0]  && b == edges[k][1])cond1=1;
                if(b == edges[k][0]  && a == edges[k][1])cond1=1;

                if(c == edges[k][0]  && d == edges[k][1])cond2=1;
                if(d == edges[k][0]  && c == edges[k][1]) cond2=1;

            }
            if(cond1 == 1 && cond2 ==1)
            {

                //printf("G.addEdge(%c%c , %c%c);\n", a,c,b,d); /// C++ Coloracion
                printf("G.add_edge(%c%c , %c%c)\n", a,c,b,d);   /// Python Dibujar grafo
                pos++;
            }
        }
    }

    printf("\nTotal de caminos %d/2 ya que hay repetidos si contamos la direccion\n",pos);
    return 0;
}
