coluna1<-c(log(200), log(500), log(800), log(1000))
coluna2<-c(1, 1, 1, 1)
A<-cbind(coluna1, coluna2)

b<-c(1.7, 1.1, 0.89, 0.79)

b<-c(log(1.7), log(1.1), log(0.89), log(0.79))
    
coeficientes<-solve(t(A)%*%A)%*%t(A)%*%b




print("asd")


