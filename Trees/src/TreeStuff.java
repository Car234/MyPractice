import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class TreeStuff {

	public static void main(String[] args) {
		Tree tree = new Tree(6);
		
		tree.add( 10);
		tree.add( 9);
		tree.add( 11);
		tree.add( 12);
		tree.add( 5);
		tree.add( 4);
		tree.add( 7);
		
		tree.preOrder(tree);
		tree.breadthSearch(tree);
		
		return;
	}

}


class Tree {
	public int data;
	public Tree left = null;
	public Tree right = null;
	
	Tree(int a) {
		this.data = a;
	}
	
	public void add(int a) {
		if (a < this.data) {
			if (this.left != null) {
				this.left.add(a);
			}
			else
				this.left = new Tree(a);
		}
		if (a > this.data) {
			if (this.right != null) {
				this.right.add(a);
			}
			else
				this.right = new Tree(a);
		}
	}
	
	public void visit(Tree r) {
		System.out.println("Hello " + r.data + "!");
	}
	
	public void preOrder(Tree r) {
		if (r != null) {
			visit(r);
			preOrder(r.left);
			preOrder(r.right);
		}
	}
	
	public void breadthSearch(Tree tree) {
		Queue<Tree> que = new LinkedList<Tree>();
		
		que.add(tree);
		
		while(!que.isEmpty()) {
			Tree r = que.remove();
			visit(r);
			if (r.left != null)
				que.add(r.left); 
			if (r.right != null)
				que.add(r.right);
		}
	}
}


