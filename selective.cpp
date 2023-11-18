#include <bits/stdc++.h>
using namespace std;
int fail=0;
int receiver(int fr,int x)
{
    if(fr==5 && fail==0)
    {
        fail=1;
        return fr;
    }
    return 1;
}
void sender( int x, int nf)
{
    int k;
    int sf=0;
    for(int y=0;y<nf;y++)
    {
        sf+=1;
        if(sf== x-2)
        {
            cout<<"Frames sent acknowledgement awaited"<<endl;
            k=receiver(y,x);
            if(x!=1)
            {
                printf("Sending frame %d again \n",k);
                printf("Frame %d sent sucessfully \n",k);
            }
            sf=0;
        }
            cout<<"Acknowledgment received for all frames\n";
    }
    cout<<"All frames sent sucessfully\n";
}

int main()
{
    int nframe,opt;
    int wsize;
    int input[20];
    while(1)
    {
        cout<<"Choose Option:\n\n1.Sender Input\n2.Send Frames \n\n";
        cin>>opt;
        switch(opt)
        {
            case 1:
            {
                cout<<"\nEnter the number of frames to be sent:";
                cin>>nframe;
                cout<<"Enter the window size as power of 2:";
                cin>>wsize;
                for(int i=0;i<nframe;i++)
                {
                    printf("\nData for frame %d: ",i+1);
                    cin>>input[i];
                    cout<<"\n";
                }
                break;
            }
            case 2:
            {
                sender(wsize,nframe);
                break;
            }
            default:
            {
                cout<<"Invalid Input"<<endl;
                exit(0);
            }
        }
    }
    return 0;
}