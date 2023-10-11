
#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include <memory>
namespace std;

class NODE
{
        public:
        int *point;
        string name;
        NODE *left;
        NODE *right;

        NODE *newNode(int k, vector<int> arr, string name)
        {
                auto temp = unique_ptr<NODE>();
                temp -> point = vector<int>(k).data();
                for(int i=0; i<k; i++)
                        temp -> point[i] = arr[i];
                temp -> left = nullptr;
                temp -> right = nullptr;
                temp -> name = name;
                return temp;
        }

        //Insert node into the kd tree
        NODE *insertNode(NODE *root, int k, vector<int> point, int depth, string name)
        {
                if(root == nullptr)
                        return newNode(k,point, name);
                else
                {
                        int curr_depth = depth % k;
                        if(point[curr_depth] < (root->point[curr_depth]))
                        {
                                root->left = insertNode(root->left, k, point,  depth+1, name);
                        }
                        else
                        {
                                root->right = insertNode(root->right, k, point,  depth+1, name);
                        }
                }
                return root;
        }


        //Performs range search - prints the list of places located within 500 mts from the given point, Boundaries is in the form of a rectangle.
        NODE *range_search(NODE *root, int k, vector<int> search_point, vector<vector<int>> point, vector<string> names)
        {
                int x1 = (search_point[0])-5;
                int x2 = (search_point[0])+5;

                int y1 = (search_point[1])-5;
                int y2 = (search_point[1])+5;

                for(int i=0; i<7; i++)
                {
                        for(int j=x1; j<=x2; j++)
                        {
                                for(int z=y1; z<=y2; z++)
                                {
                                        if((point[i][0] == j && point[i][0]!=search_point[0]) && (point[i][1] == z && point[i][1]!=search_point[1]))
                                        {
                                                cout<<names[i]<<" "<<"Located at: "<<"("<<j<<","<<z<<")"<<endl;
                                        }
                                }
                        }
                }
                return root;
        }


        //Nearest neighbour search - prints the list of all places which are closest to the given point
        void nearest_neighbour(NODE *root, int k, vector<int> search_point, vector<vector<int>> point, vector<string> names)
        {
            vector<int> nearest_arr(30), x=0, j;
            vector<string> new_names(30);
            for(int i=0; i<21; i++)
            {
                  int count = 0;
                  for(j=0; j<x; j++)
                  {
                        if(names[i] != new_names[j])
                        {
                            count++;
                        }
                  }

                  if(count==x)
                  {
                        new_names[x] = names[i];
                        x++;
                  }

            }
            //new_names has the list of places without repetition
            int min_1_dist=9999, min_2_dist=9999, min_3_dist=9999, min_4_dist=9999, min_5_dist=9999, min_6_dist = 9999, min_7_dist=9999, min_8_dist=9999, min_9_dist=9999, dist, min_1, min_2, min_3, min_4, min_5, min_6, min_7, min_8, min_9;
            vector<int> min_dists(9, INT_MAX);
            vector<int> min_indices(9, 0);

            for(int i=0; i<21; i++)
            {
                for(int z = 0; z < 9; z++)
                {
                    if(names[i] == new_names[z] && (search_point[0]!=point[i][0] && search_point[1]!=point[i][1]))
                    {
                        dist = sqrt(((point[i][0]-search_point[0])*(point[i][0]-search_point[0]))+ ((point[i][1]-search_point[1])*(point[i][1]-search_point[1])));
                        if(dist<min_dists[z])
                        {
                            min_dists[z] = dist;
                            min_indices[z] = i;
                        }
                    }
                }
            }
            cout<<"The nearest neighbours from the point ("<<search_point[0]<<","<<search_point[1]<<")"<<" are:\n";

            for(int i = 0; i < 9; i++)
            {
                cout<<new_names[i]<<" "<<"Located at: ("<<point[min_indices[i]][0]<<","<<point[min_indices[i]][1]<<")"<<endl;
            }
        }


        //Check if the given co-ordinate is present in the kd-tree
        void find_place(string place, vector<string> names, vector<vector<int>> points)
        {
            int flag =0;
            for(int i=0; i<21; i++)
            {
                if(place == names[i])
                {
                    cout<<"Found at: "<<"("<<points[i][0]<<","<<points[i][1]<<")"<<endl;
                    flag =1;
                }
            }
            if(flag ==0)
                cout<<"Place not found!\n";
        }


        //Find distance between the two given points
        float find_dist(vector<int> point1, vector<int> point2)
        {
                float dist = sqrt((point2[0] - point1[0])*(point2[0] - point1[0]) + (point2[1] - point1[1])*(point2[1] - point1[1]));
                return dist;
        }


        //Preorder of kd-tree
        void preorder(NODE *root, int k)
        {
                if(root==nullptr)
                        return;
                else
                {
                        cout<<root->name<<" at "<< "(" << root->point[0] << "," << root->point[1] <<")\n";
                        preorder(root->left, k);
                        preorder(root->right, k);
                }
        }
};
