#include <math.h>

struct route
{
   char start[50], finish[50];
   int length, up, down, max_alt, min_alt;
};

struct route* readFromInput(int *N)
{
    int i, j;
    struct route *m, temp;
    m=(struct route*)malloc(500*sizeof(struct route));

    scanf("%d", N);
    for(int i=0; i<*N; i++)
    {
        scanf(" ");
        fgets(m[i].start, 50, stdin);
        m[i].start[strcspn(m[i].start, "\n")]='\0';
        scanf("%d %d %d %d %d", &m[i].length, &m[i].up, &m[i].down, &m[i].max_alt, &m[i].min_alt);
        scanf(" ");
        fgets(m[i].finish, 50, stdin);
        m[i].finish[strcspn(m[i].finish, "\n")]='\0';
    }
    for(i=0; i<*N; i++)
    {
        for(j=0; j<*N-i-1; j++)
        {
            if(m[j].length<m[j+1].length)
            {
                temp=m[j];
                m[j]=m[j+1];
                m[j+1]=temp;
            }
        }
    }
    return m;
}

void printData(struct route m[], int N)
{
    int i, naismith;
    for(i=0; i<N; i++)
    {
        naismith=round(m[i].length/65.0+m[i].up/10.0);
        printf("From %s to %s\n", m[i].start, m[i].finish);
        printf("Uphill %d, Downhill %d\n", m[i].up, m[i].down);
        printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
        printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
        printf("\n");
        if(strcmp(m[i].start, m[i].finish)!=0)
        {
            naismith=round(m[i].length/65.0+m[i].down/10.0);
            printf("From %s to %s\n", m[i].finish, m[i].start);
            printf("Uphill %d, Downhill %d\n", m[i].down, m[i].up);
            printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
            printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
            printf("\n");
        }
    }
}

void findShort(struct route m[], int N)
{
    int L, i, naismith;
    scanf("%d", &L);
    for(i=0; i<N; i++)
    {
        if(m[i].length<=L)
        {
            naismith=round(m[i].length/65.0+m[i].up/10.0);
            printf("From %s to %s\n", m[i].start, m[i].finish);
            printf("Uphill %d, Downhill %d\n", m[i].up, m[i].down);
            printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
            printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
            printf("\n");
            if(strcmp(m[i].start, m[i].finish)!=0)
            {
                naismith=round(m[i].length/65.0+m[i].down/10.0);
                printf("From %s to %s\n", m[i].finish, m[i].start);
                printf("Uphill %d, Downhill %d\n", m[i].down, m[i].up);
                printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
                printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
                printf("\n");
            }
        }
    }
}

void findLocation(struct route m[], int N)
{
    int naismith;
    char loc[50];
    fgets(loc, 50, stdin);
    loc[strcspn(loc, "\n")]='\0';
    for(int i=0; i<N; i++)
    {
        if(strcmp(m[i].start, loc)==0)
        {
            naismith=round(m[i].length/65.0+m[i].up/10.0);
            printf("From %s to %s\n", m[i].start, m[i].finish);
            printf("Uphill %d, Downhill %d\n", m[i].up, m[i].down);
            printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
            printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
            printf("\n");
        }
        if(strcmp(m[i].start, m[i].finish)!=0)
        {
            if(strcmp(m[i].finish, loc)==0)
            {
                naismith=round(m[i].length/65.0+m[i].down/10.0);
                printf("From %s to %s\n", m[i].finish, m[i].start);
                printf("Uphill %d, Downhill %d\n", m[i].down, m[i].up);
                printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
                printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
                printf("\n");
            }
        }
    }
}

void findUpHill(struct route m[], int N)
{
    int naismith;
    for(int i=0; i<N; i++)
    {
        if(abs(m[i].up)>abs(m[i].down))
        {
            naismith=round(m[i].length/65.0+m[i].up/10.0);
            printf("From %s to %s\n", m[i].start, m[i].finish);
            printf("Uphill %d, Downhill %d\n", m[i].up, m[i].down);
            printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
            printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
            printf("\n");
        }
        if(abs(m[i].up)<abs(m[i].down))
        {
            naismith=round(m[i].length/65.0+m[i].down/10.0);
            printf("From %s to %s\n", m[i].finish, m[i].start);
            printf("Uphill %d, Downhill %d\n", m[i].down, m[i].up);
            printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
            printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
            printf("\n");
        }
    }
}

void findDownHill(struct route m[], int N)
{
    int naismith;
    for(int i=0; i<N; i++)
    {
        if(abs(m[i].up)<abs(m[i].down))
        {
            naismith=round(m[i].length/65.0+m[i].up/10.0);
            printf("From %s to %s\n", m[i].start, m[i].finish);
            printf("Uphill %d, Downhill %d\n", m[i].up, m[i].down);
            printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
            printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
            printf("\n");
        }
        if(abs(m[i].up)>abs(m[i].down))
        {
            naismith=round(m[i].length/65.0+m[i].down/10.0);
            printf("From %s to %s\n", m[i].finish, m[i].start);
            printf("Uphill %d, Downhill %d\n", m[i].down, m[i].up);
            printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
            printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
            printf("\n");
        }
    }
}

void findAltitude(struct route m[], int N)
{
    int min, max, naismith;
    scanf("%d %d", &min, &max);
    for(int i=0; i<N; i++)
    {
        if(m[i].min_alt>=min && m[i].max_alt<=max)
        {
            naismith=round(m[i].length/65.0+m[i].up/10.0);
            printf("From %s to %s\n", m[i].start, m[i].finish);
            printf("Uphill %d, Downhill %d\n", m[i].up, m[i].down);
            printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
            printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
            printf("\n");
            if(strcmp(m[i].start, m[i].finish)!=0)
            {
                naismith=round(m[i].length/65.0+m[i].down/10.0);
                printf("From %s to %s\n", m[i].finish, m[i].start);
                printf("Uphill %d, Downhill %d\n", m[i].down, m[i].up);
                printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
                printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
                printf("\n");
            }
        }
    }
}

void findTimely(struct route m[], int N)
{
    int T, naismith;
    scanf("%d", &T);
    double est;
    for(int i=0; i<N; i++)
    {
        est=m[i].length/65.0+m[i].up/10.0;
        if(est<=T)
        {
            naismith=round(est);
            printf("From %s to %s\n", m[i].start, m[i].finish);
            printf("Uphill %d, Downhill %d\n", m[i].up, m[i].down);
            printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
            printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
            printf("\n");
            if(strcmp(m[i].start, m[i].finish)!=0)
            {
               est=m[i].length/65.0+m[i].down/10.0;
               if(est<=T)
               {
                    naismith=round(est);
                    printf("From %s to %s\n", m[i].finish, m[i].start);
                    printf("Uphill %d, Downhill %d\n", m[i].down, m[i].up);
                    printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
                    printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
                    printf("\n");
               }
            }
        }
        else
        {
            est=m[i].length/65.0+m[i].down/10.0;
            if(est<=T)
            {
                naismith=round(est);
                printf("From %s to %s\n", m[i].finish, m[i].start);
                printf("Uphill %d, Downhill %d\n", m[i].down, m[i].up);
                printf("Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
                printf("Length %d, Estimated time %d min\n", m[i].length, naismith);
                printf("\n");
            }
        }
    }
}

struct route* readFromFile(int *N)
{
    int i, j;
    struct route *m, temp;
    m=(struct route*)malloc(500*sizeof(struct route));
    char S[500];
    FILE *fp;
    fgets(S, 500, stdin);
    S[strcspn(S, "\n")]='\0';
    fp=fopen(S, "r");
    if(fp!=NULL)
    {
        fscanf(fp, "%d", N);
        for(int i=0; i<*N; i++)
        {
            fscanf(fp, " ");
            fgets(m[i].start, 50, fp);
            m[i].start[strcspn(m[i].start, "\n")]='\0';
            fscanf(fp, "%d %d %d %d %d", &m[i].length, &m[i].up, &m[i].down, &m[i].max_alt, &m[i].min_alt);
            fscanf(fp, " ");
            fgets(m[i].finish, 50, fp);
            m[i].finish[strcspn(m[i].finish, "\n")]='\0';
        }
        for(i=0; i<*N; i++)
        {
            for(j=0; j<*N-i-1; j++)
            {
                if(m[j].length<m[j+1].length)
                {
                    temp=m[j];
                    m[j]=m[j+1];
                    m[j+1]=temp;
                }
            }
        }
        fclose(fp);
    }
    return m;
}

void saveData(struct route m[], int N)
{
    char S[500];
    int i, naismith;
    FILE *fp;
    fgets(S, 500, stdin);
    S[strcspn(S, "\n")]='\0';
    fp=fopen(S, "w");
    if(fp!=NULL)
    {
        for(i=0; i<N; i++)
        {
            naismith=round(m[i].length/65.0+m[i].up/10.0);
            fprintf(fp, "From %s to %s\n", m[i].start, m[i].finish);
            fprintf(fp, "Uphill %d, Downhill %d\n", m[i].up, m[i].down);
            fprintf(fp, "Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
            fprintf(fp, "Length %d, Estimated time %d min\n", m[i].length, naismith);
            fprintf(fp, "\n");
            if(strcmp(m[i].start, m[i].finish)!=0)
            {
                naismith=round(m[i].length/65.0+m[i].down/10.0);
                fprintf(fp, "From %s to %s\n", m[i].finish, m[i].start);
                fprintf(fp, "Uphill %d, Downhill %d\n", m[i].down, m[i].up);
                fprintf(fp, "Max altitude %d, Min altitude %d\n", m[i].max_alt, m[i].min_alt);
                fprintf(fp, "Length %d, Estimated time %d min\n", m[i].length, naismith);
                fprintf(fp, "\n");
            }
        }
        fclose(fp);
    }
}
