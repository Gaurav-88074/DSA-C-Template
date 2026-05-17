#include<stdio.h>
#define ll long long

typedef struct segment_tree_range_sum{
    ll * nums;
    int n;
    ll * tree;
    int size;

    void (* init)(struct segment_tree_range_sum * self,int * nums,ll n);
    ll   (*query)(struct segment_tree_range_sum * self,ll l,int r);
    void (*update)(struct segment_tree_range_sum * self,ll idx,ll value);
    void (*finalize)(struct segment_tree * self);
    void (*default_init)(struct segment_tree * self);

} _segment_tree;

void _init_segment_tree(_segment_tree *self, int * nums, ll n);
ll _query_segment_tree(_segment_tree *self, ll l, ll r);
void _update_segment_tree(_segment_tree *self, ll idx, ll value);
void _free_segment_tree(_segment_tree *self);
void _build_tree(_segment_tree *self, int node, ll start, ll end);
ll _range_sum(_segment_tree *self, ll node, ll start, ll end, ll l, ll r);
void _point_update(_segment_tree *self, ll node, ll start, ll end, ll idx, ll value);

void _default_init_segment_tree(_segment_tree *self); // Default init 


void _default_init_segment_tree(_segment_tree *self) {
    self->init = _init_segment_tree;
    self->query = _query_segment_tree;
    self->update = _update_segment_tree;
    self->finalize = _free_segment_tree;
}

void _init_segment_tree(_segment_tree *self, int * nums, ll n){
    self->n = n;
    self->size = 4 * n;
    self->nums = nums;
    self->tree = (ll * )malloc(sizeof(ll) * self->size);
}
ll _query_segment_tree(_segment_tree *self, ll l, ll r){
    return _range_sum(self, 0, 0, self->n - 1, l, r);
}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    _segment_tree obj;
    
    obj.default_init = _default_init_segment_tree;
    obj.default_init(&obj);

    obj.init(&obj,arr,n);

    
    
    return 0;
}