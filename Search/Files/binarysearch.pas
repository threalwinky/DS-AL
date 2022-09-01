uses crt;
var
	a: array[0..100] of Integer;
	m,n,x,l,r : Integer;
	check: Boolean;
begin
	a[0]:=1;
	a[1]:=2;
	a[2]:=4;
	a[3]:=7;
	a[4]:=8;
	a[5]:=9;
	x:=2{3}; 
	n:=6;
	l := 0; r := n-1;
	while l<=r do
	begin
	 	m:=(l+r) div 2;
	 	if a[m] = x then
	 	begin
	 	 	check:=true;
	 	 	break;
	 	end
	 	else if a[m] > x then r := m - 1
	 	else l := m+1;  
	 end;
	 if check = true then writeln('FOUND')
	 else writeln('NOT FOUND');
end.