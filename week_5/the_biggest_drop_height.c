#include <stdio.h>

int main(void)
{
    int width;
    int height;
    printf("Width and Height\n");
    scanf("%d %d", &width, &height);

    int each_height[width];
    printf("Each height\n");
    for (int i=0; i<width; i++)
    {
        scanf("%d", &each_height[i]);
    }
    for (int i=0; i<width; i++)
    {
        if(each_height[i]>height)
        {
            printf("height exceeded\n");
            return 1;
        }
    }

    // check the top box
    int x_pos = 0;
    int max_drop_height = 0;
    while (1)
    {
        if(x_pos == width)
            break;
        x_pos++;
        if(max_drop_height >= width-x_pos)
            break;
        int drop_height = 0;
        for (int i=0; i<width-x_pos; i++)
        {
            if (each_height[x_pos-1]>each_height[x_pos+i])
                drop_height++;
        }
        if(max_drop_height < drop_height)
            max_drop_height = drop_height;
        printf("line %d -> %d\n", x_pos, drop_height);
    }
    printf("the biggest drop height is %d\n", max_drop_height);
}