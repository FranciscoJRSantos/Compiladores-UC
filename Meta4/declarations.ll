@global.var.a = common global double 0.000000e+00, align 8
@global.var.b = common global i32 0, align 4
@global.var.c = common global i16 0, align 2
@global.var.d = common global i8 0, align 1
declare i32 @putchar(i8)
declare i32 @getchar()
define i32 @main(i32 %argc, i8** %argv) {
	call void @function.declaration.v.main.s.(i32 %argc, i8** %argv)
	ret i32 0
}

define void @what() {
	%e = alloca double, align 8
	%f = alloca i32, align 4
	%g = alloca i16, align 2
	%h = alloca i8, align 1
	ret void
}

