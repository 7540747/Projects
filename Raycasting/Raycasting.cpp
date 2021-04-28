#define OLC_PGE_APPLICATION
#define CRT_SECURE_NO_WARNINGS
#define NORTH 0
#define SOUTH 1 
#define EAST 2
#define WEST 3
#include <iostream>
#include "olcPixelGameEngine.h"

using namespace std;

struct sEdge
{
    float sx, sy;
    float ex, ey;
};

struct sCell
{
    int edgeID[4];
    bool edgeExist[4];
    bool exist = false;
};


class Raycasting : public olc::PixelGameEngine
{
public:
    Raycasting( )
    {
        sAppName = "Raycasting";
    }
private:
    sCell* world;
    int nWorldWidth = 40;
    int nWorldHeight = 30;

    vector<sEdge> vecEdges;
    vector<tuple<float, float, float>> vecVisibilityPolygonPoints;

    void ConvertTileMapToPolyMap( int sx, int sy, int w, int h, float fBlockWidth, int pitch )
    {
        //Clear the map
        vecEdges.clear( );

        for ( int x = 0; x < w; x++)
            for (int y = 0; y < h; y++ )
                for ( int j = 0; j < 4; j++ )
                {
                    world[( y + sy ) * pitch + ( x + sx )].edgeExist[j] = false;
                    world[( y + sy ) * pitch + ( x + sx )].edgeID[j] = 0;
                }

        //Iterate through the region from top left to bottom right
        for ( int x = 1; x < w - 1; x++)
            for ( int y = 1; y < h - 1; y++ )
            {
                //Create some convenient indices
                int i = ( y + sy ) * pitch + ( x + sx );
                int n = ( y + sy - 1 ) * pitch + ( x + sx );
                int s = ( y + sy + 1 ) * pitch + ( x + sx );
                int w = ( y + sy ) * pitch + ( x + sx - 1 );
                int e = ( y + sy ) * pitch + ( x + sx + 1 );

                //Check if cell exists, check for edges
                if ( world[i].exist )
                {
                    //If this cell has no western neighbour it does need a W edge
                    if ( !world[w].exist )
                    {
                        //It can either extend it from its northern neighbour if they have
                        //one, or it can start a new edge
                        if ( world[n].edgeExist[WEST] )
                        {
                            //Northern neighbour has a western edge, so grow it down
                            vecEdges[world[n].edgeID[WEST]].ey += fBlockWidth;
                            world[i].edgeID[WEST] = world[n].edgeID[WEST];
                            world[i].edgeExist[WEST] = true;
                        }
                        else
                        {
                            //Northern neighbour does not have one, so create new edge
                            sEdge edge;
                            edge.sx = ( sx + x ) * fBlockWidth; edge.sy = ( sy + y ) * fBlockWidth;
                            edge.ex = edge.sx; edge.ey = edge.sy + fBlockWidth;

                            //Add edge to polygon pool
                            int edgeID = vecEdges.size( );
                            vecEdges.push_back( edge );

                            //Update tile information with edge information
                            world[i].edgeID[WEST] = edgeID;
                            world[i].edgeExist[WEST] = true;
                        }
                    }

                    //If this cell has no eastern neighbour it does need a E edge
                    if ( !world[e].exist )
                    {
                        //It can either extend it from its northern neighbour if they have
                        //one, or it can start a new edge
                        if ( world[n].edgeExist[EAST] )
                        {
                            //Northern neighbour has a eastern edge, so grow it down
                            vecEdges[world[n].edgeID[EAST]].ey += fBlockWidth;
                            world[i].edgeID[EAST] = world[n].edgeID[EAST];
                            world[i].edgeExist[EAST] = true;
                        }
                        else
                        {
                            //Northern neighbour does not have one, so create new edge
                            sEdge edge;
                            edge.sx = ( sx + x  + 1) * fBlockWidth; edge.sy = ( sy + y ) * fBlockWidth;
                            edge.ex = edge.sx; edge.ey = edge.sy + fBlockWidth;

                            //Add edge to polygon pool
                            int edgeID = vecEdges.size( );
                            vecEdges.push_back( edge );

                            //Update tile information with edge information
                            world[i].edgeID[EAST] = edgeID;
                            world[i].edgeExist[EAST] = true;
                        }
                    }

                    //If this cell has no northern neighbour it does need a N edge
                    if ( !world[n].exist )
                    {
                        //It can either extend it from its western neighbour if they have
                        //one, or it can start a new edge
                        if ( world[w].edgeExist[NORTH] )
                        {
                            //Western neighbour has a northern edge, so grow it down
                            vecEdges[world[w].edgeID[NORTH]].ex += fBlockWidth;
                            world[i].edgeID[NORTH] = world[w].edgeID[NORTH];
                            world[i].edgeExist[NORTH] = true;
                        }
                        else
                        {
                            //Western neighbour does not have one, so create new edge
                            sEdge edge;
                            edge.sx = ( sx + x  ) * fBlockWidth; edge.sy = ( sy + y ) * fBlockWidth;
                            edge.ex = edge.sx + fBlockWidth; edge.ey = edge.sy;

                            //Add edge to polygon pool
                            int edgeID = vecEdges.size( );
                            vecEdges.push_back( edge );

                            //Update tile information with edge information
                            world[i].edgeID[NORTH] = edgeID;
                            world[i].edgeExist[NORTH] = true;
                        }
                    }

                    //If this cell has no southern neighbour it does need a S edge
                    if ( !world[s].exist )
                    {
                        //It can either extend it from its western neighbour if they have
                        //one, or it can start a new edge
                        if ( world[w].edgeExist[SOUTH] )
                        {
                            //Western neighbour has a southern edge, so grow it down
                            vecEdges[world[w].edgeID[SOUTH]].ex += fBlockWidth;
                            world[i].edgeID[SOUTH] = world[w].edgeID[SOUTH];
                            world[i].edgeExist[SOUTH] = true;
                        }
                        else
                        {
                            //Western neighbour does not have one, so create new edge
                            sEdge edge;
                            edge.sx = ( sx + x  ) * fBlockWidth; edge.sy = ( sy + y + 1 ) * fBlockWidth;
                            edge.ex = edge.sx + fBlockWidth; edge.ey = edge.sy;

                            //Add edge to polygon pool
                            int edgeID = vecEdges.size( );
                            vecEdges.push_back( edge );

                            //Update tile information with edge information
                            world[i].edgeID[SOUTH] = edgeID;
                            world[i].edgeExist[SOUTH] = true;
                        }
                    }

                }
            }
            
    }

    void CalculateVisibilityPolygon( float ox, float oy, float radius )
    {
        //Clear existing polygons
        vecVisibilityPolygonPoints.clear( );

        //For each edge in polymap
        for ( auto& e1 : vecEdges )
        {
            //Take the start point, then the end point
            for ( int i = 0; i < 2; i++ )
            {
                float rdx, rdy; 
                rdx = ( i == 0 ? e1.sx : e1.ex ) - ox;
                rdy = ( i == 0 ? e1.sy : e1.ey ) - oy;

                float baseAngle = atan2f( rdy, rdx );

                float angle = 0;

                //For each point, cast 3 rays, 1 directly at the point and 1 a little on each side
                for ( int j = 0; j < 3; j++ )
                {
                    if ( j == 0 ) angle = baseAngle - 0.0001f;
                    if ( j == 1 ) angle = baseAngle;
                    if ( j == 2 ) angle = baseAngle + 0.0001f;

                    //Creat ray along required distance
                    rdx = radius * cosf( angle );
                    rdy = radius * sinf( angle );

                    float minT1 = INFINITY;
                    float minPx = 0, minPy = 0, minAngle = 0;
                    bool bValid = false;

                    //Check for ray intersection of each edge in the scene
                    for ( auto& e2 : vecEdges )
                    {
                        //Create line segment vector
                        float sdx = e2.ex - e2.sx;
                        float sdy = e2.ey - e2.sy;

                        if ( fabs( sdx - rdx ) > 0.0f && fabs( sdy - rdy ) > 0.0f )
                        {
                            //Calculate intersection
                            float t2 = ( rdx * ( e2.sy - oy ) + ( rdy * ( ox - e2.sx ) ) ) / ( sdx * rdy - sdy * rdx );
                            float t1 = ( e2.sx + sdx * t2 - ox ) / rdx;

                            //If intersect point exists on ray and along the line segment
                            //Intersect point is valid
                            if ( t1 > 0 && t2 >= 0 && t2 <= 1.0f )
                            {
                                //Check if this intersect point is closest to the source 
                                //If it is, the store this point and ignore others
                                if ( t1 < minT1 )
                                {
                                    minT1 = t1;
                                    minPx = ox + rdx * t1;
                                    minPy = oy + rdy * t1;
                                    minAngle = atan2f( minPy - oy, minPx - ox );
                                    bValid = true;
                                }

                            }
                        }
                    }

                    if (bValid)
                        vecVisibilityPolygonPoints.push_back( { minAngle, minPy, minPx } );

                }
            }
        }

        //Sort the vector 
        sort(
            vecVisibilityPolygonPoints.begin( ),
            vecVisibilityPolygonPoints.end( ),
            [&]( const tuple<float, float, float>& t1, const tuple<float, float, float>& t2 )
            {
                return get<0>( t1 ) < get<0>( t2 );
            } );
    }


public:
    bool OnUserCreate( ) override
    {
        world = new sCell[nWorldHeight * nWorldWidth];

        for ( int x = 1; x < ( nWorldWidth - 1 ); x++ )
        {
            world[1 * nWorldWidth + x].exist = true;
            world[( nWorldHeight - 2 ) * nWorldWidth + x].exist = true;
        }

        for ( int x = 1; x < ( nWorldHeight - 1 ); x++ )
        {
            world[x * nWorldWidth + 1].exist = true;
            world[x * nWorldWidth + ( nWorldWidth - 2 )].exist = true;
        }

        return true;
    }

    bool OnUserUpdate( float fElapsedTime ) override
    {
        float fBlockWidth = 16.0f;
        float fSourceX = GetMouseX( );
        float fSourceY = GetMouseY( );

        //Set tile map blocks to on or off
        if ( GetMouse( 0 ).bReleased )
        {
            // i = y * width + x
            int i = ( ( int )fSourceY / ( int )fBlockWidth ) * nWorldWidth + ( ( int )fSourceX / ( int )fBlockWidth );
            world[i].exist = !world[i].exist;
        }

        //Take a region of the map and convert it to polymap 
        //This is done every fram here
        ConvertTileMapToPolyMap( 0, 0, 40, 30, fBlockWidth, nWorldWidth );

        if ( GetMouse( 1 ).bHeld )
        {
            CalculateVisibilityPolygon( fSourceX, fSourceY, 1000.0f );
        }

        //Drawing
        Clear( olc::BLACK );

        //If drawing rays, set an offscreen texture as the target buffer
        if ( GetMouse( 1 ).bHeld && vecVisibilityPolygonPoints.size( ) > 1 )
        {
            //Draw the triangle fan
            for ( int i = 0; i < vecVisibilityPolygonPoints.size( ) - 1; i++ )
            {
                DrawTriangle(
                    fSourceX,
                    fSourceY,

                    get<1>( vecVisibilityPolygonPoints[i] ),
                    get<2>( vecVisibilityPolygonPoints[i] ),

                    get<1>( vecVisibilityPolygonPoints[i + 1] ),
                    get<2>( vecVisibilityPolygonPoints[i + 1]) );

            }

            DrawTriangle(
                fSourceX,
                fSourceY,

                get<1>( vecVisibilityPolygonPoints[vecVisibilityPolygonPoints.size() - 1] ),
                get<2>( vecVisibilityPolygonPoints[vecVisibilityPolygonPoints.size() - 1] ),

                get<1>( vecVisibilityPolygonPoints[0] ),
                get<2>( vecVisibilityPolygonPoints[0] ) );
        }

        //Draw blocks from tilemap
        for ( int x = 0; x < nWorldWidth; x++)
            for ( int y = 0; y < nWorldHeight; y++ )
            {
                if ( world[y * nWorldWidth + x].exist )
                    FillRect( x * fBlockWidth, y * fBlockWidth, fBlockWidth, fBlockWidth, olc::RED );
            }

        //Draw edges from polymap
        for ( auto &e : vecEdges )
        {
            DrawLine(e.sx, e.sy, e.ex, e.ey);
            FillCircle( e.sx, e.ey, 3, olc::BLUE );
            FillCircle( e.ex, e.ey, 3, olc::BLUE );
        }


        return true;
    }
};

int main( )
{
    Raycasting demo;
    if ( demo.Construct( 640, 480, 2, 2 ) )
        demo.Start( );

    return 0;
}
