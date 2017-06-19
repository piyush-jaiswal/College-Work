function mean = findMean(inp, thresh)

[row, column] = size(inp);
c1  = zeros(1, 256);
c2 = zeros(1, 256);

for r = 1 : row
    for c = 1 : column
        classIndex = inp(r, c) + 1;
        if inp(r, c) <= thresh
            c1(classIndex) = c1(classIndex) + 1;
        else
            c2(classIndex) = c2(classIndex) + 1;
        end
    end
end


c1Sum = 0;
c1Pixels = 0;
for i = 1 : 256
    if c1(i) > 0
        c1Sum = c1Sum + c1(i) * (i - 1);
        c1Pixels = c1Pixels + c1(i);
    end
end

if c1Sum > 0 && c1Pixels > 0
    c1Mean = c1Sum / c1Pixels;
else
    c1Mean = 0;
end


c2Sum = 0;
c2Pixels = 0;
for i = 1 : 256
    if c2(i) > 0
        c2Sum = c2Sum + c2(i) * (i - 1);
        c2Pixels = c2Pixels + c2(i);
    end
end

if c2Sum > 0 && c2Pixels > 0
    c2Mean = c2Sum / c2Pixels;
else
    c2Mean = 0;
end

if c1Mean == 0
    mean = c2Mean;
elseif c2Mean == 0
     mean = c1Mean;
else
    mean = round((c1Mean + c2Mean) / 2);
end

end