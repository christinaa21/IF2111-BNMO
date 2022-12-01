#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree Tree(nodeinfotype Akar, BinTree L, BinTree R)
{
   BinTree result = AlokNode(Akar);
   if (result != NULL)
   {
      Left(result) = L;
      Right(result) = R;
   }
   return result;
}

void MakeTree(nodeinfotype Akar, BinTree L, BinTree R, BinTree *P)
{
   *P = Tree(Akar, L, R);
}

BinTree BetterBuildBST(int n, int diff)
{
   BinTree L, R;
   if (n % 2 == 1)
   {
      return Tree(n, NULL, NULL);
   }
   else
   {
      L = BetterBuildBST(n - diff, diff / 2);
      R = BetterBuildBST(n + diff, diff / 2);
      return Tree(n, L, R);
   }
}

addrNode AlokNode(nodeinfotype X)
{
   addrNode result;
   result = (addrNode)malloc(sizeof(TreeNode));
   if (result != NULL)
   {
      Akar(result) = X;
      Left(result) = NULL;
      Right(result) = NULL;
   }
   return result;
}

void DealokNode(addrNode P)
{
   free(P);
}

boolean IsTreeEmpty(BinTree P)
{
   return P == NULL;
}

boolean IsTreeOneElmt(BinTree P)
{
   if (!IsTreeEmpty(P))
   {
      return ((Left(P) == NULL) && (Right(P) == NULL));
   }
   else
   {
      return false;
   }
}

boolean IsUnerLeft(BinTree P)
{
   if (!IsTreeEmpty(P))
   {
      return ((Left(P) != NULL) && (Right(P) == NULL));
   }
   else
   {
      return false;
   }
}

boolean IsUnerRight(BinTree P)
{
   if (!IsTreeEmpty(P))
   {
      return ((Left(P) == NULL) && (Right(P) != NULL));
   }
   else
   {
      return false;
   }
}

boolean IsBiner(BinTree P)
{
   if (!IsTreeEmpty(P))
   {
      return ((Left(P) != NULL) && (Right(P) != NULL));
   }
   else
   {
      return false;
   }
}

void PrintPreorder(BinTree P)
{
   printf("(");
   if (!IsTreeEmpty(P))
   {
      printf("%d", Akar(P));
      PrintPreorder(Left(P));
      PrintPreorder(Right(P));
   }
   printf(")");
}

void PrintInorder(BinTree P)
{
   printf("(");
   if (!IsTreeEmpty(P))
   {
      PrintInorder(Left(P));
      printf("%d", Akar(P));
      PrintInorder(Right(P));
   }
   printf(")");
}

void PrintPostorder(BinTree P)
{
   printf("(");
   if (!IsTreeEmpty(P))
   {
      PrintPostorder(Left(P));
      PrintPostorder(Right(P));
      printf("%d", Akar(P));
   }
   printf(")");
}

void BetterPrintTree(BinTree P, int h, int lv)
{
   if (!IsTreeEmpty(P))
   {
      int i;
      for (i = 0; i < h * lv; i++)
      {
         printf(" ");
      }
      printf("%d\n", Akar(P));
      BetterPrintTree(Left(P), h, lv + 1);
      BetterPrintTree(Right(P), h, lv + 1);
   }
}

void PrintTree(BinTree P, int h)
{
   BetterPrintTree(P, h, 0);
}

boolean SearchTree(BinTree P, nodeinfotype X)
{
   if (IsTreeEmpty(P))
   {
      return false;
   }
   else if (Akar(P) == X)
   {
      return true;
   }
   else
   {
      return SearchTree(Left(P), X) || SearchTree(Right(P), X);
   }
}

addrNode SearchDaun(BinTree P, nodeinfotype X)
{
   if (IsTreeEmpty(P))
   {
      return NULL;
   }
   else if (IsTreeOneElmt(P))
   {
      if (Akar(P) == X)
      {
         return P;
      }
      else
      {
         return NULL;
      }
   }
   else
   {
      addrNode ret = SearchDaun(Left(P), X);
      if (ret != NULL)
      {
         return ret;
      }
      else
      {
         return SearchDaun(Right(P), X);
      }
   }
}

int NbNode(BinTree P)
{
   if (IsTreeEmpty(P))
   {
      return 0;
   }
   else
   {
      return 1 + NbNode(Left(P)) + NbNode(Right(P));
   }
}

int NbDaun(BinTree P)
{
   if (IsTreeOneElmt(P))
   {
      return 1;
   }
   else if (IsUnerLeft(P))
   {
      return NbDaun(Left(P));
   }
   else if (IsUnerRight(P))
   {
      return NbDaun(Right(P));
   }
   else
   { // IsBiner
      return NbDaun(Left(P)) + NbDaun(Right(P));
   }
}

int Level(BinTree P, nodeinfotype X)
{
   if (Akar(P) == X)
   {
      return 1;
   }
   else if (IsBiner(P))
   {
      if (SearchTree(Left(P), X))
      {
         return 1 + Level(Left(P), X);
      }
      else
      {
         return 1 + Level(Right(P), X);
      }
   }
   else if (IsUnerLeft(P))
   {
      return 1 + Level(Left(P), X);
   }
   else if (IsUnerRight(P))
   {
      return 1 + Level(Right(P), X);
   }
}

int Tinggi(BinTree P)
{
   if (IsTreeEmpty(P))
   {
      return 0;
   }
   else
   {
      int tR = Tinggi(Right(P));
      int tL = Tinggi(Left(P));
      return 1 + (tR > tL ? tR : tL);
   }
}

void AddDaunTerkiri(BinTree *P, nodeinfotype X)
{
   if (IsTreeEmpty(*P))
   {
      *P = AlokNode(X);
   }
   else if (IsUnerRight(*P))
   {
      Left(*P) = AlokNode(X);
   }
   else
   {
      AddDaunTerkiri(&(Left(*P)), X);
   }
}

void AddDaun(BinTree *P, nodeinfotype X, nodeinfotype Y, boolean Kiri)
{
   addrNode Q = SearchDaun(*P, X);
   if (Kiri)
   {
      Left(Q) = AlokNode(Y);
   }
   else
   {
      Right(Q) = AlokNode(Y);
   }
}

void DelDaunTerkiri(BinTree *P, nodeinfotype *X)
{
   if (IsTreeOneElmt(*P))
   {
      *X = Akar(*P);
      BinTree N = *P;
      *P = NULL;
      DealokNode(N);
   }
   else if (IsUnerRight(*P))
   {
      DelDaunTerkiri(&(Right(*P)), X);
   }
   else
   {
      DelDaunTerkiri(&(Left(*P)), X);
   }
}

void DelDaun(BinTree *P, nodeinfotype X)
{
   if (!IsTreeEmpty(*P))
   {
      if (IsTreeOneElmt(*P))
      {
         if (Akar(*P) == X)
         {
            addrNode Q = *P;
            *P = NULL;
            DealokNode(Q);
         }
      }
      else
      {
         DelDaun(&Left(*P), X);
         DelDaun(&Right(*P), X);
      }
   }
}

boolean BSearch(BinTree P, nodeinfotype X)
{
   if (IsTreeEmpty(P))
   {
      return false;
   }
   else if (Akar(P) == X)
   {
      return true;
   }
   else
   {
      if (X < Akar(P))
      {
         return BSearch(Left(P), X);
      }
      else
      {
         return BSearch(Right(P), X);
      }
   }
}

void InsSearch(BinTree *P, nodeinfotype X)
{
   if (IsTreeEmpty(*P))
   {
      MakeTree(X, NULL, NULL, P);
   }
   else if (X == Akar(*P))
   {
      return;
   }
   else if (X < Akar(*P))
   {
      InsSearch(&(Left(*P)), X);
   }
   else if (X > Akar(*P))
   {
      InsSearch(&(Right(*P)), X);
   }
}

void DelBtree(BinTree *P, nodeinfotype X)
{
   if (Akar(*P) == X)
   {
      addrNode Q = *P;
      *P = NULL;
      DealokNode(Q);
   }
   else if (X < Akar(*P))
   {
      DelBtree(&Left(*P), X);
   }
   else
   {
      DelBtree(&Right(*P), X);
   }
}

void BuildTreeFromWord(BinTree *T, Word w, int *idx)
{
   (*idx)++;
   if (w.TabWord[*idx] == ')')
   {
      *T = NULL;
   }
   else
   {
      int simpul = (int)w.TabWord[(*idx)] - 48;

      while (48 <= (int)w.TabWord[(*idx) + 1] && (int)w.TabWord[(*idx) + 1] <= 57)
      {
         (*idx)++;
         simpul = 10 * simpul + (int)w.TabWord[*idx] - 48;
      }

      *T = AlokNode(simpul);
      (*idx)++;
      BuildTreeFromWord(&(Left(*T)), w, idx);
      BuildTreeFromWord(&(Right(*T)), w, idx);
   }
   (*idx)++;
}
