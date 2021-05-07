##Lab6

###Questions:
####The code relies on virtual functions. Could the code have been written without virtual functions?
As the code is written, no it would not be possible. Without it we could not implement chessmove in the same way and we would not make the pieces depended on chesspiece which is needed for chessboards state parameter.

#####Capturingmove calls a protected virtual function but is not virtual in itself. Noncapturingmoves/Capturingmoves are public virtual functions. What is your opinion of that design difference? Write your thoughts.
NoncapturingmoveS and capturingmoveS need to be able to be called outside the class while capturemove are to be called only inside the class hence the protected part. We dont want capturemove to be called directly unlinke capturemoveS.

####Should ChessPiece have been an abstract class?
yes, without it the functions cannot find a reference to the pieces and going around it is EXTREAMLY DIFFICULT.

####There was no separate unit test for each function in this assignement, instead you tested several functions at once with different boards. What are the benefits and drawbacks for this kind of testing compared to unit tests?
The benefits om this type of testing is that I can get visual testing which makes it easy to see if I did anything wrong with the pieces. This way I can see what happens instead of seeing that it didn't occur like I wanted to. Drawback is that I cannot test individual functions but do it as a whole.

####What is the problem with a diamond inheritence?
The program will have a hard time recognizing which capturemove/capturemoves/noncapturemove/noncapturemoves is being called and create errors.

####What do you think of the general design of this code? What could be improved?
In practice, this code is well designed and could be useful when you have different chess pieces and use a matrix which is dependent of chesspieces. Improving is difficult because lists and vectors rewuire chesspiece and going around it is not possible.



