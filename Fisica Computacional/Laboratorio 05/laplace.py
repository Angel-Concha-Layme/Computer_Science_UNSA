import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm


def edplaplace(ua,ub,uc,ud,n,m,maxiter,error):
    u = np.zeros((n+2,m+2))
    for i in range(n+2):
        u[i,0]=uc
        u[i,m+1]=ud
    for j in range(m+2):
        u[0,j]=ua
        u[n+1,j]=ub
    p= (ua+ub+uc+ud)/4
    for i in range(1,n+1):
        for j in range(1,m+1):
            u[i,j]=p
    k=0
    conv =0
    while k<maxiter and conv==0:
        k=k+1
        t=u
        for i in range(1,n+1):
            for j in range(1,m+1):
                u[i,j]=0.25*(u[i-1,j]+u[i+1,j]+u[i,j+1]+u[i,j-1])
        if np.linalg.norm((u-t), np.inf)/np.linalg.norm(u,np.inf)<error:
            conv=1
    if conv==1:
        print(u)
        print(k)
        x = np.linspace(1,m+2,m+2) 
        y = np.linspace(1,n+2,n+2) 
        X,Y = np.meshgrid(x,y) 
        fig = plt.figure()
        ax = fig.add_subplot(projection='3d')
        surf = ax.plot_surface(X, Y, u, cmap=cm.coolwarm, linewidth=0, antialiased=False)
        fig.colorbar(surf, shrink=0.5, aspect=5)
        plt.show()

    else:
        print('no converge')



#EJERCICIO 1
edplaplace(20,300,80,0,40,40,100,0.001)

#EJERCICIO 2
#edplaplace(120,0,120,0,40,40,100,0.001)



"""
function y = edplaplace(ua,ub,uc,ud,n,m,maxiter,error)
clear u
for i = 1:n+2
    u(i,1)=uc;
    u(i,m+2)=ud;
end

for j = 1:m+2
    u(1,j)=ua;
    u(n+2,j)=ub;
end
p= (ua+ub+uc+ud)/4;
for i=2:n+1
    for j=2:m+1
        u(i,j)=p;
    end
end

k=0;
conv =0;
while k<maxiter & conv==0
    k=k+1;
    t=u;
    for i=2:n+1
        for j=2:m+1
            u(i,j)=0.25*(u(i-1,j)+u(i+1,j)+u(i,j+1)+u(i,j-1))
        end
    end
    if norm((u-t), inf)/norm(u,inf)<error
        conv=1;
    end
end

if conv==1
    disp(u)
    disp(k)
    [x,y]=meshgrid(1:m+2,1:n+2);
    surf(x,y,u)
    shading flat 
else
    disp('no converge');
end

"""