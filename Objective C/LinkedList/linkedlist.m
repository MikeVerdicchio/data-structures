#import <stdio.h>
#import <stdlib.h>
#import <Foundation/NSObject.h>

@interface ListNode: NSObject{
		int value;
		ListNode* next;
	}


	- (void) setValue: (int) val;
	- (void) setNext: (ListNode*) temp;

	- (int) value;
	- (ListNode*) next;
@end

@implementation ListNode
	- (void) setValue: (int) val {
		value = val;
	}
	
	- (void) setNext: (ListNode*) temp {
		next = temp;	
	}
	
	- (int) value {
		return value;
	}
	
	- (ListNode*) next {
		return next;
	}	
@end
		

int main (int argc, char *argv[]) {
	// Initialize ListNode variables
	ListNode *head = nil;
	ListNode *tail = nil;
	ListNode *temp = nil;
	ListNode *next = nil;

	// Prompt number of elements in LinkedList
	int n;
	printf("Enter how many values to input: ");
	scanf("%d", &n);
		
	// Add elements to the LinkedList
	int i;
	int val;
	for (i = 1; i <= n; i++) {
		printf("Enter value %d: ", i);
		scanf("%d", &val);

		temp = [ListNode new];
		[temp setValue: val];
		[temp setNext: nil];

		if (head == nil) {
			head = temp;
		} else {
			[tail setNext: temp];
		}

		tail = temp;
	}

	// Prints the elements in the LinkedList
	if (head == nil) {
		printf("There are no elements in the LinkedList. \n");
		return 0;
	} else {
		temp = head;
		printf("LinkedList elements: ");
	
		do {
			printf("%d ", [temp value]);
			temp = [temp next];
		} while([temp next] != nil);

		printf("%d ", [temp value]);

		printf("\n");
	}

	// Delete ListNodes
	temp = head;
	do {
		temp = next;
		next = [next next];
		free(temp);
	} while([temp next] != nil);

	// Return
	return 0;
}