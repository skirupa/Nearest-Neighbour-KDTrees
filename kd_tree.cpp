
#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class NODE
{
        public:
        int *point;
        string name;
        NODE *left, *right;

        NODE *newNode(int k, int arr[], string name)
        {
                NODE *temp = new NODE;
                temp -> point = new int[k];
                for(int i=0; i<k; i++)
                        temp -> point[i] = arr[i];
                temp -> left = NULL;
                temp -> right = NULL;
                temp -> name = name;
                return temp;
        }

        //Insert node into the kd tree
        NODE *insertNode(NODE *root, int k, int point[], int depth, string name)
        {
                if(root == NULL)
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
        NODE *range_search(NODE *root, int k,int search_point[], int point[21][2], string names[])
        {
                int x1 = (search_point[0])-5;
                int x2 = (search_point[0])+5;

                int y1 = (search_point[1])-5;
                int y2 = (search_point[1])+5;

                for(int i=0; i<7; i++)
                {
                        for(int j=x1; j<=x2; j++)
                        {
                                for(int k=y1; k<=y2; k++)
                                {
                                        if((point[i][0] == j && point[i][0]!=search_point[0]) && (point[i][1] == k && point[i][1]!=search_point[1]))
                                        {
                                                cout<<names[i]<<" "<<"Located at: "<<"("<<j<<","<<k<<")"<<endl;
                                        }
                                }
                        }
                }
                return root;
        }


        //Nearest neighbour search - prints the list of all places which are closest to the given point
        void nearest_neighbour(NODE *root, int k, int search_point[], int point[21][2], string names[])
        {
            int nearest_arr[30], x=0, j;
            string new_names[30];
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
            for(int i=0; i<21; i++)
            {

                if(names[i] == new_names[0] && (search_point[0]!=point[i][0] && search_point[1]!=point[i][1]))
                {
                    dist = sqrt(((point[i][0]-search_point[0])*(point[i][0]-search_point[0]))+ ((point[i][1]-search_point[1])*(point[i][1]-search_point[1])));
                    if(dist<min_1_dist)
                    {
                        min_1_dist = dist;
                        min_1 = i;
                    }
                }
                if(names[i] == new_names[1] && (search_point[0]!=point[i][0] && search_point[1]!=point[i][1]))
                {
                    dist = sqrt((point[i][0]-search_point[0])*(point[i][0]-search_point[0]) + (point[i][1]-search_point[1])*(point[i][1]-search_point[1]));
                    if(dist<min_2_dist)
                    {
                        min_2_dist = dist;
                        min_2 = i;
                    }
                }
                if(names[i] == new_names[2] && (search_point[0]!=point[i][0] && search_point[1]!=point[i][1]))
                {
                    dist = sqrt((point[i][0]-search_point[0])*(point[i][0]-search_point[0]) + (point[i][1]-search_point[1])*(point[i][1]-search_point[1]));
                    if(dist<min_3_dist)
                    {
                        min_3_dist = dist;
                        min_3 = i;
                    }
                }
                if(names[i] == new_names[3] && (search_point[0]!=point[i][0] && search_point[1]!=point[i][1]))
                {
                    dist = sqrt((point[i][0]-search_point[0])*(point[i][0]-search_point[0]) + (point[i][1]-search_point[1])*(point[i][1]-search_point[1]));
                    if(dist<min_4_dist)
                    {
                        min_4_dist = dist;
                        min_4 = i;
                    }
                }
                if(names[i] == new_names[4] && (search_point[0]!=point[i][0] && search_point[1]!=point[i][1]))
                {
                    dist = sqrt((point[i][0]-search_point[0])*(point[i][0]-search_point[0]) + (point[i][1]-search_point[1])*(point[i][1]-search_point[1]));
                    if(dist<min_5_dist)
                    {
                        min_5_dist = dist;
                        min_5 = i;
                    }
                }
                if(names[i] == new_names[5] && (search_point[0]!=point[i][0] && search_point[1]!=point[i][1]))
                {
                    dist = sqrt((point[i][0]-search_point[0])*(point[i][0]-search_point[0]) + (point[i][1]-search_point[1])*(point[i][1]-search_point[1]));
                    if(dist<min_6_dist)
                    {
                        min_6_dist = dist;
                        min_6 = i;
                    }
                }
                if(names[i] == new_names[6] && (search_point[0]!=point[i][0] && search_point[1]!=point[i][1]))
                {
                    dist = sqrt((point[i][0]-search_point[0])*(point[i][0]-search_point[0]) + (point[i][1]-search_point[1])*(point[i][1]-search_point[1]));
                    if(dist<min_7_dist)
                    {
                        min_7_dist = dist;
                        min_7 = i;
                    }
                }
                if(names[i] == new_names[7] && (search_point[0]!=point[i][0] && search_point[1]!=point[i][1]))
                {
                    dist = sqrt((point[i][0]-search_point[0])*(point[i][0]-search_point[0]) + (point[i][1]-search_point[1])*(point[i][1]-search_point[1]));
                    if(dist<min_8_dist)
                    {
                        min_8_dist = dist;
                        min_8 = i;
                    }
                }
                if(names[i] == new_names[8] && (search_point[0]!=point[i][0] && search_point[1]!=point[i][1]))
                {
                    dist = sqrt((point[i][0]-search_point[0])*(point[i][0]-search_point[0]) + (point[i][1]-search_point[1])*(point[i][1]-search_point[1]));
                    if(dist<min_9_dist)
                    {
                        min_9_dist = dist;
                        min_9 = i;
                    }
                }
            }
            cout<<"The nearest neighbours from the point ("<<search_point[0]<<","<<search_point[1]<<")"<<" are:\n";
            cout<<new_names[0]<<" "<<"Located at: ("<<point[min_1][0]<<","<<point[min_1][1]<<")"<<endl;
            cout<<new_names[1]<<" "<<"Located at: ("<<point[min_2][0]<<","<<point[min_2][1]<<")"<<endl;
            cout<<new_names[2]<<" "<<"Located at: ("<<point[min_3][0]<<","<<point[min_3][1]<<")"<<endl;
            cout<<new_names[3]<<" "<<"Located at: ("<<point[min_4][0]<<","<<point[min_4][1]<<")"<<endl;
            cout<<new_names[4]<<" "<<"Located at: ("<<point[min_5][0]<<","<<point[min_5][1]<<")"<<endl;
            cout<<new_names[5]<<" "<<"Located at: ("<<point[min_6][0]<<","<<point[min_6][1]<<")"<<endl;
            cout<<new_names[6]<<" "<<"Located at: ("<<point[min_7][0]<<","<<point[min_7][1]<<")"<<endl;
            cout<<new_names[7]<<" "<<"Located at: ("<<point[min_8][0]<<","<<point[min_8][1]<<")"<<endl;
            cout<<new_names[8]<<" "<<"Located at: ("<<point[min_9][0]<<","<<point[min_9][1]<<")"<<endl;
        }


        //Check if the given co-ordinate is present in the kd-tree
        void find_place(string place, string names[], int points[21][2])
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
        float find_dist(int point1[2], int point2[2])
        {
                float dist = sqrt((point2[0] - point1[0])*(point2[0] - point1[0]) + (point2[1] - point1[1])*(point2[1] - point1[1]));
                return dist;
        }


        //Preorder of kd-tree
        void preorder(NODE *root, int k)
        {
                if(root==NULL)
                        return;
                else
                {
                        cout<<root->name<<" at "<< "(" << root->point[0] << "," << root->point[1] <<")\n";
                        preorder(root->left, k);
                        preorder(root->right, k);
                }
        }
};

