uses crt;
var
	a:array[0..100] of Integer;
	dem : Integer;

procedure qs(left, right : Integer);
var i, j ,x, temp : Integer;
begin
	i:=left;
	j:=right;
	x:=a[(left+right) div 2];
	while i<=j do 

	begin
		while a[i] < x do i:=i+1;
		while a[j] > x do j:=j-1;
		if i <= j then
		begin
			temp := a[i];
			a[i] := a[j];
			a[j] := temp;
			i:=i+1;
			j:=j-1;
		end;
	end;
	if (left < j) then qs(left, j);
	if (i < right) then qs(i, right);
end;
begin
	randomize;
	for dem := 0 to 19 do a[dem]:=random(100);
	for dem := 0 to 19 do write(a[dem], ' ');
	qs(0, 19);
	writeln;
	for dem := 0 to 19 do write(a[dem], ' '); 
end.