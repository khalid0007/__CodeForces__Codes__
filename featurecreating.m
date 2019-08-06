% This code will extract all features from a given image
% Loading Image
img_var=imread('bangla_dui.png');
% Converting to gray scale
gray_img=rgb2gray(img_var);
% Resize to 32 x 32
resize_img=imresize(gray_img,[32,32],'nearest');
% Converting to binary
bin_img=im2bw(resize_img);


% This strores all cordinates of all black pixels
vector_cordinate=[];
% stores centroid co-ordinates of all 8 octants
centroid_octant=[];
% stores all 3 projections of octant
projections=[]
%octant 1
for  i=1:16,
    for j=1:i,
        if bin_img(i, j) == 1,
            vector_cordinate=[vector_cordinate;[i,j]];
        end
    end
end

sort(vector_cordinate);

length=size(vector_cordinate,1);

projections=[projections,abs(vector_cordinate(1,1)-vector_cordinate(len,1))];

projections=[projections,abs(vector_cordinate(1,2)-vector_cordinate(len,2))];




% Append the centroid value
centroid_octant=[centroid_octant ,mean(vector_coordinate)];

%octant 2
vector_cordinate=[]; 
for  i=1:16,
    for j=i:16,
        if bin_img(i, j) == 1,
            vector_cordinate=[vector_cordinate;[i,j]];
        end
    end
end

centroid_octant=[centroid_octant ,mean(vector_coordinate)];

%octant 3
vector_cordinate=[]; 
for  i=1:16,
    for j = 16:16 + i,
        if bin_img(i, j) == 1,
            vector_cordinate=[vector_cordinate;[i,j]];
        end
    end
end

centroid_octant=[centroid_octant ,mean(vector_coordinate)];

%octant 4
vector_cordinate = [];

for  i=1:16,
    for j=32-i:32,
        if bin_img(i,j)==1,
            vector_cordinate=[vector_cordinate;[i,j]];
        end
    end
end

centroid_octant=[centroid_octant ,mean(vector_coordinate)];
%octant 5
vector_cordinate = [];

for  i=17:32,
    for j=1:16-i+16,
        if bin_img(i,j)==1,
            vector_cordinate=[vector_cordinate;[i,j]];
        end
    end
end

centroid_octant=[centroid_octant ,mean(vector_coordinate)];

%octant 6
vector_cordinate = [];

for  i=17:32,
    for j=32-i:16,
        if bin_img(i,j)==1,
            vector_cordinate=[vector_cordinate;[i,j]];
        end
    end
end
centroid_octant=[centroid_octant ,mean(vector_coordinate)];


%octant 7
vector_cordinate = [];

for  i=17:32,
    for j=17:i,
        if bin_img(i,j)==1,
            vector_cordinate=[vector_cordinate;[i,j]];
        end
    end
end
centroid_octant=[centroid_octant ,mean(vector_coordinate)];

%octant 8
vector_cordinate = [];

for  i=17:32,
    for j=i:32,
        if bin_img(i,j)==1,
            vector_cordinate=[vector_cordinate;[i,j]];
        end
    end
end
centroid_octant=[centroid_octant ,mean(vector_coordinate)];

            

