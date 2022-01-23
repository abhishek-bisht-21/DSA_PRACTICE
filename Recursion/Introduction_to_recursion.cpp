

// ____________________________________________________Print Decreasing___________________________________________________

void printDecreasing(int n){
    if(n==0)
    return ;
    
    cout<<n<<''\n'';
    printDecreasing(n-1);

}


// ________________________________________________Print Increasing________________________________________________________________________

void printIncreasing(int n){
    if(n==0)
    return ;
    
    printIncreasing(n-1);
    cout<<n<<''\n'';
    
}



// __________________________________________Print Decreasing and Increasing__________________________________________________________________

void printIncDec(int n)
{
    if(n==0)
    return ;
    
    cout<<n<<''\n'';
    printIncDec(n-1);
    cout<<n<<''\n'';
    
}



// _______________________________________________________ Factorial___________________________________________________________________________________________

int factorial(int n)
{
    if(n==0)
    return 1;
    
    int fnm1=factorial(n-1); //Factorial of n-1
    
    return n*fnm1;
    
}

// _____________________________________________________________POWER__________________________________________________________________________

int power(int x,int n){
    if(n==0)
    return 1;
    
    int smlans=power(x,n-1); //x^(n-1)
    return x*smlans; 
}


// _____________________________________________________Power Logarithmic_____________________________________________________________________

int powerLogarithmic(int x,int n){
    if(n==0)
    return 1;
    
    int pxnb2=powerLogarithmic(x,n/2);
    
    if(n%2==0){
        return pxnb2*pxnb2;
    }
    else{
        return x*pxnb2*pxnb2;
    }
    
}

// ______________________________________________________Print Zigzag___________________________________________________________________________

void pzz(int n){
    if(n==0)
    return ;
    
    cout<<n<<" ";
    pzz(n-1);
    cout<<n<<" ";
    pzz(n-1);
    cout<<n<<" ";
    
    
}

// ____________________________________________________Tower of hanoi__________________________________________________________________________________

void toh(int n, int t1id, int t2id, int t3id){
    if(n == 0){
      return;
    }
    
    toh(n - 1, t1id, t3id, t2id);
    cout<<n<<"["<<t1id<<" -> "<<t2id<<"]"<<endl;
    toh(n - 1, t3id, t2id, t1id);
  }