/*Program implementing kd trees and performs the following functions;
1.Print preorder of the kd tree
2.Search for a given place
3.Nearest neighbour search
4.Range search
5.Insert a new place
6.Calculate the distance between two places */
#include <iostream>
#include "kd_tree.cpp"

int main()
{
    NODE *root = NULL, temp;
    float dist;
    char choice;
    string place_to_search;
    int k=2,n=21;
    vector<int> point_to_search(2), point1(2), point2(2);
    vector<vector<int>> points{{1,1}, {5,5}, {2,9}, {5,12}, {2,16}, {8,3}, {8,7}, {9,10}, {7,16}, {10,15}, {11,4}, {11,9}, {13,12}, {14,3}, {14,14}, {15,8},{19,3},{19,12}, {20,15}, {21,9}, {22,2}};
    vector<string> names = {"Waterfalls", "School", "Museum", "Hospital", "Church", "Mosque", "Mall", "School", "School", "Temple", "Hospital", "Police Station", "Mosque", "Temple", "Hospital", "School", "Police Station", "Mall", "School", "Hospital", "Church"};
    for(int i=0; i<21; i++)
    {
        root = temp.insertNode(root, k, points[i], 0, names[i]);
    }
    cout<<"---------------------------------------------------------------------------------------";
    cout<<"\nLOVE TO TRAVEL ??????\n\n\n";
    cout<<"\t\tLook around ROME - the city of visible history\n\n";
    cout<<"\t   '''''''''Experience a different vision of life'''''''''\n";
    cout<<"---------------------------------------------------------------------------------------";
    cout<<"\n\nDo you want to explore ROME?  (ENTER 'Y' - YES & 'N' - NO)\n";
    cin>>choice;
    if(choice == 'Y')
    {
        temp.preorder(root,k);
    }

        cout<<"\n\nChoose the requied option: \n1.List of places\n2.Search for a given place\n3.Nearest neighbour search\n4.Range search\n5.Calculate distance between two places\n";
        cin>>select;
        do{
        switch(select)
        {
            case 1:
                temp.preorder(root, k);
                break;

            case 2:
                cout<<"Enter the name of the place to be searched[Ex: Mall] :";
                cin>>place_to_search;
                temp.find_place(place_to_search, names, points);
                break;

            case 3:
                cout<<"Enter the co-ordinates for which nearest neighbour search has to be performed[Ex: 4 4] :";
                for(int i=0; i<2; i++)
                        cin>>point_to_search[i];

                temp.nearest_neighbour(root, 2, point_to_search, points, names);
                break;

            case 4:
                cout<<"Enter the co-ordinates for which range search has to be performed (Range is assumed to be within 500 mts)[Ex: 2 9] :";
                for(int i=0; i<2; i++)
                    cin>>point_to_search[i];

                root = temp.range_search(root, 2, point_to_search, points, names);
                break;

            case 5:
                cout<<"Enter the co-ordinates of the two points between which distance has to be found[Ex: 2 3 4 5] :";
                for(int i=0; i<2; i++)
                    cin>>point1[i];
                for(int i=0; i<2; i++)
                    cin>>point2[i];
                dist = temp.find_dist(point1,point2);
                cout<<"Distance: "<<dist<<endl;
                break;
        }
        cout<<"\n\nChoose the requied option: \n1.List of places\n2.Search for a given place\n3.Nearest neighbour search\n4.Range search\n5.Calculate distance between two places\n6.Exit\n";
        cin>>select;
        }while(select!=6);

}
